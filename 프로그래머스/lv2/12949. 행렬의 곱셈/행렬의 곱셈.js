function solution(arr1, arr2) {
    return arr1.map(행 => (
        arr2[0].map((_, 열) => {
            let result = 0;
            행.forEach((ele, idx) => {
                result += ele * arr2[idx][열];
            })
            return result;
        })
    ))
}