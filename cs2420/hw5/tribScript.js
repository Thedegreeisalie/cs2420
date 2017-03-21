var trib = function (n, node) {
	var tree = tribHelper(n);
		node.appendChild(tree.html);
		//node.style = "display: inline-block;";
	  node.setAttribute("id", "fib");
};

function tribHelper(n) {
	var value;
	var div = document.createElement('div');
	div.setAttribute("class", "fib");

	// leaf nodes aka. base case
	if (n <= 2) {
	if (n === 0) {
		value = 0;
	} 
	else if (n === 1) {
		value = 0;
	}
	else if (n === 2) {
		value = 1;
	}
		var p = document.createElement('p');
		p.textContent = 'trib(' + n + ') = ' + value;
		div.appendChild(p);
	} 
	else {
		var left = tribHelper(n - 1);
		var clas = left.html.getAttribute("class");
		left.html.setAttribute("class", clas + " fib-left");
		
		var right = tribHelper(n - 2);
		clas = right.html.getAttribute("class");
		right.html.setAttribute("class", clas + " fib-right");
		
		var altLeft = tribHelper(n-3);
		clas = altLeft.html.getAttribute("class");
		altLeft.html.setAttribute("class", clas + " fib-right");
		
		value = left.value + right.value + altLeft.value;
		var p = document.createElement('p');
		p.textContent = 'Trib(' + n + ') = ' + value;
		div.appendChild(p);

		div.appendChild(left.html);
		div.appendChild(right.html);
		div.appendChild(altLeft.html);
	}
	return { 'value': value, 'html': div };
}