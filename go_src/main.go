package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"time"

	"github.com/mkideal/cli"
	. "leochan007/xtp.go/go_src/xtp_wrapper"
)

type argT struct {
	cli.Helper
	Username string `cli:"u,username" usage:"account" prompt:"type account"`
	Password string `pw:"p,password" usage:"password of account" prompt:"type the password"`
	Debug    bool   `pw:"d,debug" usage:"debug flag" prompt:"if it is in debug mode"`
	File     string `pw:"f,file" usage:"file for strategy" prompt:"type json file name"`
}

type StockMap map[string]string

var (
	Stocks = make(StockMap)
)

func main() {

	cli.Run(new(argT), func(ctx *cli.Context) error {
		argv := ctx.Argv().(*argT)
		ctx.String("username=%s, password=%s debug:%v file:%v\n", argv.Username, argv.Password, argv.Debug, argv.File)

		folder := "bin"

		trader_api := GoCreateLCTraderApi(1, folder)
		trader_spi := GoCreateLCTraderSpi()
		Go_trader_apiRegisterSpi(trader_api, trader_spi)
		loginResult := Go_trader_apiLogin(trader_api, "120.27.164.69", 6001, argv.Username, argv.Password)

		if loginResult == 0 {
			fmt.Println("trader login OK.")
		} else {
			fmt.Println("trader failed.")
		}

		quote_api := GoCreateLCQuoteApi(1, folder)
		quote_spi := GoCreateLCQuoteSpi()
		Go_quote_apiRegisterSpi(quote_api, quote_spi)
		loginResult = Go_quote_apiLogin(quote_api, "120.27.164.138", 6002, argv.Username, argv.Password)

		if loginResult == 0 {
			fmt.Println("quote login OK.")
			Stocks["xtp*"] = "xtp*"
			Go_quote_apiSubscribeMarketData(quote_api, Stocks, 1)
			Go_quote_apiSubscribeMarketData(quote_api, Stocks, 2)
		} else {
			fmt.Println("login failed.")
		}

		time.Sleep(1 * time.Second)

		inputReader := bufio.NewReader(os.Stdin)
		for {
			input, err := inputReader.ReadString('\n')
			if err != nil {
				fmt.Println("There ware errors reading, exiting program.")
				return nil
			}
			input = strings.ToUpper(strings.TrimSpace(input))
			fmt.Println("input:", input)
			if input == "Q" {
				fmt.Println("it will shutdown in seconds!")
				GoReleaseLCQuoteApi(quote_api)
				GoReleaseLCQuoteSpi(quote_spi)
				GoReleaseLCTraderApi(trader_api)
				GoReleaseLCTraderSpi(trader_spi)
				break
			}
		}
		SafeShutdown()

		return nil
	})
}
