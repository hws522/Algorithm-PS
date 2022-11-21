function solution(babbling) {
    let answer = 0;
    let 두번이상반복 = ['ayaaya', 'yeye', 'woowoo', 'mama'];
    while (babbling.length) {
        let 단어 = babbling.pop();
        if (두번이상반복.some(반복단어 => 단어.includes(반복단어))) continue;
        단어 = 단어.replace(/aya|ye|woo|ma/g, '');
        if (단어.length === 0) answer++;
    }

    return answer;
}
                     
