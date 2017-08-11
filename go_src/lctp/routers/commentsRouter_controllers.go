package routers

import (
	"github.com/astaxie/beego"
	"github.com/astaxie/beego/context/param"
)

func init() {

	beego.GlobalControllerRouter["leochan007/xtp.go/go_src/lctp/controllers:UserController"] = append(beego.GlobalControllerRouter["leochan007/xtp.go/go_src/lctp/controllers:UserController"],
		beego.ControllerComments{
			Method: "Login",
			Router: `/user/login1`,
			AllowHTTPMethods: []string{"post"},
			MethodParams: param.Make(),
			Params: nil})

	beego.GlobalControllerRouter["leochan007/xtp.go/go_src/lctp/controllers:UserController"] = append(beego.GlobalControllerRouter["leochan007/xtp.go/go_src/lctp/controllers:UserController"],
		beego.ControllerComments{
			Method: "Logout",
			Router: `/user/logout`,
			AllowHTTPMethods: []string{"post"},
			MethodParams: param.Make(),
			Params: nil})

}
