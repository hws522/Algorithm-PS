function sol(input) {
    let answer = "";
    const N = +input[0];
    const numbers = input
        .slice(1)
        .map(Number)
        .sort((a, b) => a - b); // 모든 숫자를 numbers 배열에 받아 오름차순 정렬

    answer += `${Math.round(numbers.reduce((s, v) => s + v, 0) / N)}\n`; // 산술평균
    answer += `${numbers[Math.floor(N / 2)]}\n`; // 중앙값

    const map = new Map();
    let max = 1;
    for (let number of numbers) {
        if (map.has(number)) {
            max = Math.max(max, map.get(number) + 1);
            map.set(number, map.get(number) + 1);
        } else map.set(number, 1);
    } // map 자료구조를 통해 숫자 별 빈도수 기록

    const maxArr = [];
    for (let [key, val] of map) {
        if (val === max) maxArr.push(key);
    } // maxArr 배열에 최빈값 후보에 해당하는 모든 원소를 넣어준다.

    answer += maxArr.length === 1 ? `${maxArr[0]}\n` : `${maxArr[1]}\n`;
    // 최빈값이 여러개면 두번째로 작은 값, 1개라면 최빈값.
    answer += `${numbers[N - 1] - numbers[0]}\n`; // 범위
    return answer;
}

// 백준에서 입력 받기.
const input = [];
require("readline")
    .createInterface(process.stdin, process.stdout)
    .on("line", (line) => {
        input.push(line);
    })
    .on("close", () => {
        console.log(sol(input));
        process.exit();
    });