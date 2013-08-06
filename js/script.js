$(document).ready (
	function () {
		var websocket = io.connect("http://192.168.0.113:8888");
		$('#button_up').click (
            		function() {
                		websocket.emit('newOrder', 'w \r\n');
			});
		$('#button_down').click (
                        function() {
                                websocket.emit('newOrder', 's \r\n');
                        });
		$('#button_right').click (
                        function() {
                                websocket.emit('newOrder', 'd \r\n');
                        });
		$('#button_left').click (
                        function() {
                                websocket.emit('newOrder', 'a \r\n');
                        });
		$('#button_stop').click (
                        function() {
                                websocket.emit('newOrder', 'p \r\n');
                        });

	});
