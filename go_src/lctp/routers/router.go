package routers

import (
	"leochan007/xtp.go/go_src/lctp/controllers"
	"github.com/astaxie/beego"
)

func init() {
    beego.Router("/", &controllers.MainController{})
}
