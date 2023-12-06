function solution(msg) {
    const answer = [];
    const ALPHABET = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'];
    
    let char = '';
    
    msg.split('').forEach((ele, idx, arr) => {
        char += ele;
        if(ALPHABET.indexOf(char) < 0) {
            answer.push(ALPHABET.indexOf(char.replace(/.$/, '')) + 1);
            ALPHABET.push(char);
            char = ele;
        }
    })
    
    if(char) answer.push(ALPHABET.indexOf(char) + 1);
    
    return answer;
}