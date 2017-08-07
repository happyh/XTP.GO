package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"time"

	. "leochan007/xtp.go/go_src/xtp_wrapper"
)

type StockMap map[string]string

var (
	Stocks = make(StockMap)
)

func main() {
	folder := "bin"

	trader_api := GoCreateLCTraderApi(1, folder)
	trader_spi := GoCreateLCTraderSpi()
	Go_trader_apiRegisterSpi(trader_api, trader_spi)
	loginResult := Go_trader_apiLogin(trader_api, "120.27.164.69", 6001, "15030798", "UgDUqNeK")

	if loginResult == 0 {
		fmt.Println("trader login OK.")
	} else {
		fmt.Println("trader failed.")
	}

	quote_api := GoCreateLCQuoteApi(1, folder)
	quote_spi := GoCreateLCQuoteSpi()
	Go_quote_apiRegisterSpi(quote_api, quote_spi)
	loginResult = Go_quote_apiLogin(quote_api, "120.27.164.138", 6002, "15030798", "UgDUqNeK")

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
			return
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
}
