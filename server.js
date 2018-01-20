"use strict"

const http = require("http")
const fs = require("fs")
const url = require("url")

http.createServer((request, response) => {

    let path = url.parse(request.url).pathname
    let data

    path = "/demo"+(path=="/"?"/index.html":path)

    console.log(path)

    switch(path){
        case "/demo/demo.wasm":
            try{
                data = fs.readFileSync(__dirname+path)
            }catch(e){}
            break
        default:
            try{
                data = fs.readFileSync(__dirname+path, "utf8")
            }catch(e){}
    }

    // console.log(data)
    response.end(data)

}).listen(1337, () => console.log("Server Listening on port 1337"))

