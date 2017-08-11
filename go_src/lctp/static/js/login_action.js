$(document).ready(function() {
// 使用 jQuery异步提交表单
$('#login_form').submit(function() {
	jQuery.ajax({
	url:'user/login',
	data:$('#login_form').serialize(),
	type:"POST",
	beforeSend:function()
	{
		$('#login_btn').attr("disabled","true");
		//$('#editRealMsgImg').show();
	},
	success:function()
	{
		$('#login_btn').attr("disabled","false");
	}
	});
	returnfalse;
});

});
