var roll;
document.querySelector('#init').onclick = function() {
	 roll  = Module.cwrap('roll_dice','number');
	 this.remove();
}
var out = document.querySelector('#out');

document.querySelector('#click').onclick = function() {
	var rand = roll();
	out.textContent += rand + ', ';
	console.log(rand);
}