function solution(board, moves) {
    var answer = 0;
    let 바구니 = [];
    
    for(let i = 0; i < moves.length; i++){
        for(let j = 0; j < board.length; j++){
            if(board[j][moves[i] - 1] !== 0) {
                if(바구니.at(-1) === board[j][moves[i] - 1]) {
                    바구니.pop();
                    answer += 2;
                } else {
                    바구니.push(board[j][moves[i] - 1]);
                }
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }
    
    return answer;
}