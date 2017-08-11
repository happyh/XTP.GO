package controllers

import (
	"fmt"

	"github.com/astaxie/beego"
)

type UserController struct {
	beego.Controller
}

// @router /user/login [post]
func (c *UserController) Login() {
	fmt.Printf("enter Login")
	c.TplName = "main.tpl"
}

// @router /user/logout [post]
func (c *UserController) Logout() {
	fmt.Printf("enter Logout")
}
