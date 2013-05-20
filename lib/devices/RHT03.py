var sys=require("sys");
var exec=require("child_process").exec;
var child;
var http=require("http");
var Stdout;
 
child=exec("Adafruit_DHT 22 4",function(error, stdout,stderr){
        Stdout=stdout;
});
 
http.createServer(function(request,response){
        response.writeHead(200,{"Content-Type":"text/plain"});
        response.write(Stdout);
        response.end();
}).listen(8888);