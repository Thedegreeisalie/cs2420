/*
 * This is a JavaScript Scratchpad.
 *
 * Enter some JavaScript, then Right Click or choose from the Execute Menu:
 * 1. Run to evaluate the selected text (Ctrl+R),
 * 2. Inspect to bring up an Object Inspector on the result (Ctrl+I), or,
 * 3. Display to insert the result in a comment after the selection. (Ctrl+L)
 * 
 * Eric Falor wrote most of this and Jeremiah Moore changed almost 3 lines..
 */
 
var fib = function (n, node) {
	// var element = document.getElementsByClassName("fib");
	// if (element){
	// 	while(element[0]) {
	//     	element[0].parentNode.removeChild(element[0]);
	// 	}

	// }
	var tree = fibHelper(n);
		node.appendChild(tree.html);
		//node.style = "display: inline-block;";
	  node.setAttribute("id", "fib");
};

function fibHelper(n) {
	var value;
	var div = document.createElement('div');
	div.setAttribute("class", "fib");

	// leaf nodes aka. base case
	if (n < 2) {
		if (n === 0) {
			value = 0;
		} 
		else if (n === 1) {
			value = 1;
		}
		var p = document.createElement('p');
		p.textContent = 'Fib(' + n + ') = ' + value;
		div.appendChild(p);
	} 
	else {
		var left = fibHelper(n - 1);
		var clas = left.html.getAttribute("class");
		left.html.setAttribute("class", clas + " fib-left");
		
		var right = fibHelper(n - 2);
		clas = right.html.getAttribute("class");
		right.html.setAttribute("class", clas + " fib-right");

		value = left.value + right.value;
		var p = document.createElement('p');
		p.textContent = 'Fib(' + n + ') = ' + value;
		div.appendChild(p);

		div.appendChild(left.html);
		div.appendChild(right.html);
	}
	return { 'value': value, 'html': div };
}

var trib = function (n, node) {
	var tree = tribHelper(n);
		node.appendChild(tree.html);
		//node.style = "display: inline-block;";
	  node.setAttribute("id", "trib");
};

function tribHelper(n) {
	var value;
	var div = document.createElement('div');
	div.setAttribute("class", "trib");

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
		left.html.setAttribute("class", clas + " trib-left");
		
		var right = tribHelper(n - 2);
		clas = right.html.getAttribute("class");
		right.html.setAttribute("class", clas + " trib-right");
		
		var altLeft = tribHelper(n-3);
		clas = altLeft.html.getAttribute("class");
		altLeft.html.setAttribute("class", clas + " trib-right");
		
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

var pell = function (n, node) {

	var tree = PellHelper(n);
		node.appendChild(tree.html);
		//node.style = "display: inline-block;";
	  node.setAttribute("id", "pell");
};

function PellHelper(n) {
	var value;
	var div = document.createElement('div');
	div.setAttribute("class", "pell");

	// leaf nodes aka. base case
	if (n < 2) {
		if (n === 0) {
			value = 0;
		} 
		else if (n === 1) {
			value = 1;
		}
		var p = document.createElement('p');
		p.textContent = 'pell(' + n + ') = ' + value;
		div.appendChild(p);
	} 
	else {
		var left = PellHelper(n - 1);
		var clas = left.html.getAttribute("class");
		left.html.setAttribute("class", clas + " pell-left");
		
		var right = PellHelper(n - 2);
		clas = right.html.getAttribute("class");
		right.html.setAttribute("class", clas + " pell-right");

		value = 2*(left.value + right.value);
		var p = document.createElement('p');
		p.textContent = 'Pell(' + n + ') = ' + value;
		div.appendChild(p);

		div.appendChild(left.html);
		div.appendChild(right.html);
	}
	return { 'value': value, 'html': div };
}

// IIFE = Immediately-invoked function expression
// An anonymous function which we create, invoke, then throw away.
// It exists to meet these aims:
//   0) Avoid clobbering an existing variable named "div" in the global namespace. I don't have
//      another variable called "div" today, but this protects my webpage in the event that I
//      later incorporate other JavaScript programs from elsewhere.
//   1) Collect a few related program statements and keep them together in a single unit.
// https://en.wikipedia.org/wiki/Immediately-invoked_function_expression
// ( function(color, id) {
// 	var div = document.createElement('div');
// 	div.setAttribute('class', color + ' shadowed stuff-box');
// 	div.setAttribute('id', id);
// 	document.body.appendChild(div);
// }('red', 'fib'));
// we make the red fib tree element
// fib(11, document.querySelector('.red'));

// divMakerMaker() is a function which returns a function
// divMakerMaker() takes two arguments and creates a function which requires
// no arguments of its own, but upon invocation "remembers" the functions it
// was created with
var divMakerMaker = function(color, id) {
	if(!document.getElementById(id)){
		return function() {
			var div = document.createElement('div');
			div.setAttribute('class', color + ' shadowed stuff-box');
			div.setAttribute('id', id);
			document.body.appendChild(div);
		}
	};
};

var blueDiv = divMakerMaker('blue', 'fib');
var redDiv = divMakerMaker('red', 'pell');
var yellowDiv = divMakerMaker('yellow', 'trib');

var destroy = function(id){
	if (document.getElementById(id)) {
		var element = document.getElementById(id);
	    element.parentNode.removeChild(element);
	}
}