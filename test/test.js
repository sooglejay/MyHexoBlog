var url  = require("url"),
fs=require("fs"),
path = require("path");
var pathname=path.join(__dirname,'./index.html');
console.log("pathname comes :")

console.log(pathname)

console.log("pathname over :")

fs.exists(pathname, function(exists){
    if(exists){
         fs.readFile(pathname,function (err,data){
                console.log(pathname+"文件内容："+data.toString());
                
            });

    }else{
         fs.readFile(pathname,function (err,data){
                console.log("err:"+err);
            });
    }
})
