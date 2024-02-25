## AtCoder

[atcoder.jp](https://atcoder.jp/)

## My Account
[tic40](https://atcoder.jp/users/tic40)

### C++ Template file

[template.cpp](https://github.com/tic40/atcoder/blob/main/template.cpp)

### Scripts

#### Create contest template

`$ scripts/createContestTemplate.sh {directory name}`

#### Download test input

* Need node.js

`$ node scripts/downloadSampleInput.js {url}`

e.g.
```
$ node scripts/downloadSampleInput.js https://atcoder.jp/contests/abc342/tasks/abc342_a
[created test1]
yay

[created test2]
egg

[created test3]
zzzzzwz

$ ls
test1 test2 test3
```

#### Run test

`$ scripts/runTest.sh`

### Compile

#### aliases
```
alias gcce='g++ -std=gnu++2b -O2 -Wall -Wextra -ld_classic main.cpp && ./a.out'
alias gccac='g++ -std=gnu++2b -O2 -Wall -Wextra -ld_classic -I /path/to/ac-library main.cpp'
alias gccace='g++ -std=gnu++2b -O2 -Wall -Wextra -ld_classic -I /path/to/ac-library main.cpp && ./a.out'
```

### Libraries

- [libraries/ac-library](https://github.com/atcoder/ac-library)
