const point = { R: 0, T: 0, C: 0, F: 0, J: 0, M: 0, A: 0, N: 0 };
const pointToMbti = (a_point, b_point) => point[a_point] >= point[b_point] ? a_point : b_point;

function solution(survey, choices) {
    survey.forEach((question, index) => 
        choices[index] >= 4 ? 
        point[question.charAt(0)] += 4 - choices[index] : 
        point[question.charAt(1)] += choices[index] - 4);
    return pointToMbti('R', 'T') + pointToMbti('C', 'F') + pointToMbti('J', 'M') + pointToMbti('A', 'N');
};

