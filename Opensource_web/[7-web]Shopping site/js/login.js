function checklogin(){
    var id = document.Myform.id.value;
    var pw = document.Myform.pw.value;

    if(id === 'admin' && pw === '1234'){
        alert("Login Success!");
        location.href = "home.html";
    }
    else {
        alert("Login Failed!");
        location.href = "login.html";
    }

}