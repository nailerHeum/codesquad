### Shell Script Basic

------

Oh-my-zsh 사용중



**사용자 관련 명령어 **

------

- `sudo` : “superuser do”
- `adduser` : 계정을 추가시킨다. 다양한 사용법이 존재하기에 [링크를 달았다.](https://www.howtoforge.com/linux-adduser-addgroup-command/)
- `addgroup` : 유저그룹을 추가시킨다.
- `usermod` : 사용자 계정 속성 변경 ([변경 옵션들에 대하여](https://jang8584.tistory.com/243))
- `who` : 호스트에 로그인한 사용자 정보 출력
- `w`  : 서버 정보와 함께 사용자 정보를 알려주는 명령어
- `last` : 접속기록 확인
- `chmod` : (character mode) 
  - file의 permission 변경을 위한 명령어
- `chown` : (character own)
  - file의 소유자나 소유 그룹을 변경하기 위한 명령어
- `chgrp` : (character group)
  - file의 사용자 그룹 변경



------



**시스템 관련 명령어**

```bash
df
du
find
grep
free
kill
ln
mount
ps
```

------

**기타**

------

- htop
  - 상호작용 시스템 모니터 프로세스 뷰어이자 프로세스 관리자
  - process 관련 명령어들 수행가능(signal 가능)
- tmux
  - terminal multiplexer



**Environmental Variables**

```
$ env
$ echo $HOME
$ echo $SHELL
$ echo $PWD
$ echo $PATH
```



**export, source**

```
$ export 변수명=값 #새로운 환경변수 설정
$ source 스크립트파일 #현재 셸에서 스크립트 실행
```

스크립트 파일을 이용해서 환경변수를 설정하기 위해서는 source 명령을 써야 한다!



**shell에서 파일을 실행하려면?**

1. 셸은 프로세스를 하나 생성 - fork (부모 프로세스를 복사하는 것)
2. 프로세스를 실행한 프로그램으로 변경 - exec (복사된 프로세스를 자식 프로세스로 바꿔줌)
3. 프로그램이 완료되면 해당 프로세스는 사라짐 (Life cycle)



**시작 스크립트**

```javascript
[ .profile, .bashrc, .bash_profile ]
```

셸을 시작할 때 자동으로 시작되는 스크립트들 주로 셸 초기화, 환경변수 설정 등을 위해 사용됨



### Shell Script 실습!!!

------

BASH = 뛰어난 명령 라인 쉘인 동시에 스크립팅 언어

- 스크립팅 언어의 가장 큰 장점은 소스 파일을 어떤 운영 체제에나 쉽게 이식할 수 있으며 바로 그자리에서 번역기를 통해 실행할 수 있다는 것이다. 



`chmod 700 ./hello.sh` 를 통해 파일 소유자의 permisson을 모두 풀어준다.

예를 들어 rwxr-xr-x 일 경우

파일 소유자(user)는 read, write, execute 권한 모두를 갖고 있고

소유 group 과 파일과 관련없는자들(others)는 read와 execute의 권한만 갖는 것이다.

이러한 권한을 숫자로 표현하면 read는 4, write는 2, execute는 1을 부여받아,

부여된 권한의 숫자들을 더해서 chmod 700 ./test.txt, chmod 644 ./test.txt와 같은 명령어를 만드는 것이다.



**hello.sh**

```bash
#!bin/bash
echo "hello"
```

`#!bin/bash` 는 이 script를 실행하기 위해서 bash 번역기를 사용하라고 알려준 것이다. 



첫번째 라인은 주석이 아니고 첫번째 라인 다음에 오는 "`#`"으로 시작하는 모든 라인은 주석이다

### test.sh

```bash
VAR1=$#
echo "num=$#"
echo "parameter: $0 $1 $2 $3"
echo "parameters: $@"
echo "VAR1 = $VAR1"
echo 'VAR1 = $VAR1'
$ sh test.sh

# result
# num=0
# parameter: ./test.sh
# parameters:
# VAR1 = 0
# VAR1 = $VAR1
```



$#은 넘어온 argument의 갯수를 말한다.

`$0 $1 $2 $3` 은 각 argument들을 변수로 담은 것이고, 

`$@`는 모든 parameter들을 보여준다.



```bash
true
echo $?
false
echo $?
echo $RANDOM
echo $RANDOM

//result
0
1
2787
1515
```



`$?` the exit status of the last executed command

따라서 위의 실행값이 출력된다.

`$RANDOM` integer in the range 0 - 32767 에서 난수를 생성한다.



**hello2 만들어보기**

```bash
$ ./hello2.sh James
Hello, James
I am ./hello2.sh
```

이름을 입력받고 그걸 Hello,와 합쳐 출력해야하는데 

2번째 argument에 이름이 입력되므로 `$1` 을 사용한다. 

그리고 ./hello2.sh는 `$0` 를 사용하고 2열로 출력한다. 

따라서 코드는

```bash
echo "Hello, $1"
echo "I'm $0"

# result
#	$ ./hello2.sh Nailer
# Hello, Nailer
# I'm ./hello2.sh
```



**Redirection**

```
> : 표준 출력을 지정 파일로  
< : 키보드 대신 파일로부터 입력받음
2> : 표준 에러를 지정 파일로
2>&1 : 표준 에러를 표준 출력으로
1>&2 : 표준 출력을 표준 에러로
$ ./my.sh > log.txt 2>&1
```

0 = Standard Input

1  = Standard Output

2 = Standard Error



**Pipe**

앞 프로그램의 표준 출력이 후속 프로그램의 표준 입력으로 사용됨

```bash
ps -A | grep ssh
```



**키보드 입력 받기**

```bash
$ read INPUT
Hello, Woowa
$ echo $INPUT
Hello, Woowa
```



**환경변수 iteration**

```bash
#!/bin/bash
NUM=0
for i in $@
do
    echo "$NUM : $i"
    NUM=$(($NUM+1))
done
```



**test**

```
test 조건식
```

조건식이 참이면 0, 거짓이면 1을 리턴함

```
$ test 1 = 2; echo $?
$ [ 1 = 2 ]; echo $?
```





**if 문**

```bash
if [ expr ]
then
    ...
elif [ expr ]
then
    ...
else
    ...
fi
```

elif에 주의할 것!



**File, Directory & String Test**

```
[ -d file ] 
[ -f file ]
[ -z string ]
$ [ -z $zero ] && echo "t" || echo "f"
$ zero="hello"
$ [ -z $zero ] && echo "t" || echo "f"
```



**숫자비교**

```
[ 3 -eq 5 ]
[ 3 -ne 5 ]
[ 3 -gt 5 ]
[ 3 -ge 5 ]
[ 3 -le 5 ]
[ 3 -lt 5 ]
```



**문자열 비교**

[[ expr ]] 를 사용하는 것이 좋다.

```bash
[[ $a == $b ]]
[[ $a == hello* ]]
[[ $a != $b ]]
```



**실습**

숫자를 입력받으면 해당 단을 출력하는 프로그램을 bash로 짜 보세요.

팁: `seq 5 10` 명령을 써보자.

**gugudan.sh**

```bash
let "GUGUDAN = $1 * 9"
seq $1 $1 $GUGUDAN
```

팁의 seq 를 사용하여 구구단을 할 수 있도록 하였다.





 **cron / crontab**

주기적으로 스크립트를 자동실행할 때 사용함

<http://www.slideshare.net/hoyoung2jung/crontab-39470064>

```
$ select-editor #vim 선택
$ crontab -e 
* * * * * /home/ubuntu/time.sh >> time.txt
# save and quit (:wq)
```



추후 bash scripting에 대한 추가적인 공부가 필요할 경우

[Bash Scripting Tutorial](https://ryanstutorials.net/bash-scripting-tutorial/) 을 참고한다.



### 