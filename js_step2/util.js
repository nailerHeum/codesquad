(function callModuleChecker(){
  result = new Date();
  console.log("WELCOME UTIL MODULE : " + result);
})();

function checkNumber(value) {
  return (typeof value === "number") ? true : false;
}

module.exports.sum = (arr) => {
  result = result && 0;

  for (let i = 0; i < arr.length; i++) {
      if(!checkNumber(arr[i])) continue;
      result += arr[i]
  }

  return result;
}
