// 순열 사이클
//
// issue 1   : 큐 안에 남은 요소 초기화 문제
// 해결 방법 : 반복문 안에 큐를 선언
//
// issue 2   : 중복 if 문으로 아무것도 계산되지 않는 문제
// 해결 방법 : 필요 없는 if문을 하나를 제거

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N;

int main() {
	cin >> T;

	for (int k = 0; k < T; k++) {
		int cnt = 0;					// 매 테스트 케이스 마다 카운터 초기화
		int visited[1010] = { 0 };		// 이전 사이클에 포함되었는지 Check

		vector<int> v[1010];			// 연결 리스트 이용
		
		cin >> N;

		for (int i = 1; i <= N; i++) {
			int temp;
			cin >> temp;
			v[i].push_back(temp);
		}

		for (int i = 1; i <= N; i++) {
			queue<int> q;				// 사이클 확인 시 마다 큐를 초기화 하여 남은 요소를 비워줌

			if (!visited[i]) {			// 이전 사이클에서 사용한 요소는 제외
				q.push(i);
			}

			while (!q.empty()) {
				int temp = q.front();
				if (temp == i && visited[i]) {	// 자기 자신으로 돌아온 경우 카운트 추가
					cnt++;
					break;
				}
				visited[temp] = 1;				// 사용한 요소 체크

				for (int j = 0; j < v[temp].size(); j++) {	// 연결되어있는 요소 큐에 추가
						visited[v[temp][j]] = 1;
						q.push(v[temp][j]);
				}
				q.pop();						// 사용한 요소 큐에서 제거
			}
		}

		cout << cnt << endl;
	}
}