function solution(s) {
  const bracket = {
    '(': ')',
    '[': ']',
    '{': '}',
  };
  const bracketLeft = Object.keys(bracket);

  return s.split('').reduce((acc, cur, idx) => {
    const curStr = s.slice(idx) + s.slice(0, idx);
    const stack = [];
    for (const curChar of curStr) {
      if (bracketLeft.includes(curChar)) stack.push(curChar);
      else {
        if (bracket[stack.pop()] !== curChar) return acc;
      }
    }
    return stack.length === 0 ? ++acc : acc;
  }, 0);
}
