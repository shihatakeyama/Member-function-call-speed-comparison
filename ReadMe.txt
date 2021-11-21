配列内の要素呼び出し時間比較


配列内の各要素をを関数呼び出しするアクセス時間を計測する。
配列内の各要素はクラスである。

人によって書きなれたソースコードの記述方法は何種類かあると思いますが、
コンピュータが処理する上で、効率的な記述方法を調べた。

<環境>
・Windows10 64bit
・Intel Core i7-10700
・VisualStudio 2013

<計測方法>
1024個の配列を宣言して、中の要素全てに順番にCallする。
上記の処理を10000000回繰り返した期間をそてぞれの記述の仕方で計測した。

＜実行結果＞
処理速い順に列挙した。
実行環境によって速度の違いはあると思いますが、
私の環境で何度か計測したところ、はほぼ以下の順位になった。
・C言語にある配列[]によるアクセス
・for文のrange-basedによるアクセス
・vectorコンテナの[]によるアクセス
・vectorコンテナのat()によるアクセス。

==== Call Speed Comparison START ====
Number of loops : 10000000
Array::[] bracket call time     : 3002 ms
vector::[] bracket call time    : 3022 ms
for range call time     : 3012 ms
vector::at() call time  : 3389 ms
==== Call Speed Comparison END ====

