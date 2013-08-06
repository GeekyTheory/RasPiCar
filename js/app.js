var http = require('http'),
	socketio = require('socket.io');
var SerialPort = require("serialport").SerialPort;
var serialPort = new SerialPort("/dev/ttyACM0", {
	baudrate: 9600
}, false);

serialPort.on("open", function () {
  	console.log('Open serial port');
  	serialPort.on('data', function(data) {
    		console.log('data received: ' + data);
  	});  
	serialPort.write("p \r\n", function(err, results) {
    		console.log(err);
    		console.log('results ' + results);
  	});  
});

var server = http.createServer(function(request, response) {
  	response.writeHead(200, {"Content-Type": "text/html"});
  	response.end();
}).listen(8888);

var io = require('socket.io').listen(server);
io.sockets.on('connection', function(socket) {
        socket.on('newOrder', function(order) {
                //io.sockets.emit('setFrame', order);
		console.log('--->   '+order);
		serialPort.write(order,function(err, results) {
	                console.log(err);
        	        console.log('results ' + results);
        	});
        });
});
