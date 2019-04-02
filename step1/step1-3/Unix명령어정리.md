**unix기반 os의 기본 명령어들**

----

- `tree / -L 1` (tree [디렉토리이름] [-L 깊이])
- ` | ` : pipe

  - 앞 명령의 표준출력이 뒷 명령의 표준입력이 된다.
- `echo <인자>`   :  매개변수를 표준출력으로 보내주는 명령어이다.
- ` 'something1' > 'something2'` : redirection
  - something1의 표준 출력을 something2의 표준입력으로 사용한다. 그리고 something2의 기존 내용은 덮어쓰기 당한다.
  - `>>`  : 추가 모드로 사용할 수 있다.
- `cat` : 표준입력을 표준출력으로 보내주는 것.
  - `cat <파일명>` : 파일을 표준출력
  - `cat < '파일명'` : 파일의 내용을 표준입력으로 redirection해준다. 

- `ls` : 파일 리스트 출력

- `grep` : 표준입력 중에서 매개변수와 일치하는 것만 보여준다.

- `less <파일명>` (긴 파일의 내용을 끊어서 표시)

  - q : 종료
  - g : 처음으로
  - G : 끝으로
  - /단어 : 문서에서 '단어'를 검색
  - space, enter, 화살표, hjkl(vim이랑 똑같음) : 페이지 이동

- `history` : 명령어 이력 표시

- `cp <파일1> <파일2> ` : 파일1의 내용을 파일2에 copy

  - 다양한 옵션들은 여기로 [cp options](https://corej21.tistory.com/42)

- `mv <file or dir> <dir2>` : dir2로 이동

- `rm <file or dir>`  : 해당 file이나 dir 삭제 

  - -r : recursive option 하위항목 전체다 삭제(dir 삭제시 사용)
  - -f: forced option 관리자권한 강제 삭제

- `find <dir> -name "filename"`: 해당 filename을 해당 dir에서 찾아본다.

- `touch <filename>` : 0 byte file 생성

- `pbcopy` , `pbpaste` : 맥전용 명령으로 클립보드 복사/붙여넣기로 활용

  ex) 

  ```
  cat some.txt | pbcopy
  pbpaste > some2.txt
  ```

- 더 공부하려면

  - <https://opentutorials.org/course/2598>
  - <https://github.com/denysdovhan/bash-handbook/blob/master/translations/ko-KR/README.md>
  - <http://linuxcommand.org/lc3_learning_the_shell.php>
  - <https://linuxjourney.com/>
  - <https://www.edx.org/course/introduction-linux-linuxfoundationx-lfs101x-0>