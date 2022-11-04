function solution(participant, completion) {
    let 참여인원 = new Map();
    let 성공인원 = new Map();
    let 실패인원 = '';
    
    participant.sort();
    completion.sort();
    
    for(let i = 0; i < participant.length; i++){
        참여인원.set(i, participant[i]);
        if(i !== participant.length - 1) 성공인원.set(i, completion[i]);
    };
    
    for(let i = 0; i < 참여인원.size; i++){
        if(참여인원.get(i) !== 성공인원.get(i)){
            실패인원 = 참여인원.get(i);
            break;
        } 
    }
    
    return 실패인원;
}