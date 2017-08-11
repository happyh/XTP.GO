package routers

import (
	"github.com/astaxie/beego"
	"leochan007/xtp.go/go_src/lctp/controllers"
)

func init() {
	beego.Router("/", &controllers.MainController{})
	beego.Include(&controllers.UserController{})
}
