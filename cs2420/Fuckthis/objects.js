var hi = function(n) { return n};

var obj = {'one': 1, 
          'name': 'Humphrey',
          'func': hi, 
          'name' : 'Porter'} 

var pattern = /\w+/g,
    string = "how often a word occurs in this string this string is long, and it's only getting longer, but that's not a bad thing, not really, one two three four one one one one zero one",
    matchedWords = string.match(pattern),
    count = {};


for (var i = 0; i < matchedWords.length; ++i) {
  if (count[matchedWords[i]] === undefined) {
    count[matchedWords[i]] = 1;
  }
  else {
    count[matchedWords[i]]++;
  }
}
count["this doesn't fit the mold"] = "renegade";

count["this doesn't fit the mold"]
