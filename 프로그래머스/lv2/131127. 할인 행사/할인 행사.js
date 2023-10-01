function solution(want, number, discount) {
  let answer = 0;
  let result = [];
  for (let i = 0; i < number.length; i++) {
    for (let j = 0; j < number[i]; j++) {
      result.push(want[i]);
    }
  }
    
  discount.forEach((ele, idx) => {
    const wantTarget = [...result];
    const discountTarget = discount.slice(idx, idx + 10);
      
    discountTarget.forEach(target => {
        let findIndex = wantTarget.findIndex(data => target === data);
        if(findIndex >= 0) wantTarget.splice(findIndex, 1);
    })
    
      if(wantTarget.length === 0) answer++;
  });
    
  return answer;
}
