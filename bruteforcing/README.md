# 브루트포스 알고리즘

조합 가능한 모든 문자열을 하나씩 대입해 보는 방식으로 암호를 해독하는 방법.

브루트 포스 공격(brute force attack) 또는 키 전수조사(exhaustive key search), 무차별 대입 공격(無差別代入攻擊) 등으로도 부른다. 

흔히 수학 문제를 원시적으로 푸는 방법인 '수 대입 노가다'의 학술적 버전이다. 주로 암호학에서 연구되는 방법이나, 다른 알고리즘 분야에서도 사용되고 있다.

영어로 brute는 "짐승 같은, 난폭한"이라는 뜻이고, brute-force는 "난폭한 힘, 폭력"이라는 뜻이다. 

오래 걸리는 데다 자원이 엄청나게 들어서 얼핏 보면 무식하다고 생각할 수도 있겠지만, 항상 정확도 100%를 보장한다는 점에서 암호 해독법 중 가장 확실하고 무서운 방법이다. 

이론적으로 가능한 모든 경우의 수를 다 검색해 보는 것이라 정확도 100%가 항상 보장되니, 암호학에서는 가장 확실한 방법으로 통용되고 있다. 

무엇보다도 암호 확인 작업은 손으로 입력한 문자열의 동일 여부를 확인하는 것이기 때문에, 가능한 경우의 수를 하나씩 대입하다 보면 언젠가는 암호를 찾을 수 있게 되는 식이다. 

다만 정말로 그냥 무식하게 때려 박는 건 아니고, 숫자만 섞어서 대입해 보기 한 번, 로마자만 섞어서 대입해 보기 한 번 이런 식으로 하다가 안 되면 나머지를 순차적으로 하는 식으로 특정 규칙에 따라 우선순위를 두고 하기도 한다.

또한 브루트 포스의 특장점은 거의 완벽하게 병렬 작업이 가능하다는 점이다.

이 때문에 병렬 프로그래밍 기법을 사용하거나, GPGPU를 이용하기도 하며, 여러 대의 컴퓨터를 연결해서 동시에 작업할 수도 있다. 

이렇게 하면 투자 자원에 비례해서 문제를 해결하는 시간을 줄일 수 있다. 

즉, 컴퓨터를 10대 쓰면 10일 걸릴 작업을 1일 만에 끝낼 수 있다는 이야기이다. (암달의 법칙 때문에 이런 식으로 병렬화가 잘 되는 작업은 흔치 않다.)