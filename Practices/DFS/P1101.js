'use strict';

var word = ['y', 'i', 'z', 'h', 'o', 'n', 'g'];
var mat = new Array(100);
var mark = new Array(100);
for (var i = 0; i < 100; i++) {
    var tmp = new Array(100);
    //mat.push(tmp);
    mark.push(tmp);
}
var dx = [-1, -1, -1, 1, 1, 1, 0, 0];
var dy = [-1, 0, 1, -1, 0, 1, -1, 1];
var n;
process.stdin.on('readable', () => {
    n = process.stdin.read();
});
for (var i = 0; i < n; i++) {
    process.stdin.on('readable', () => {
        mat[i] = process.stdin.read();
    });
}


