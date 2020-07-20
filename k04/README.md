# 課題4 レポート

aa83988848 薗田光太郎

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明

1.8: char型の変数id[9]、idf[9]を宣言

1.9: int型の変数zを宣言し、1を代入

1.10: double型の変数gender_num、heightを宣言

1.17: データファイル名を入力させ、fname1に格納

1.18: 入力させた文字列の最後にエンターキーが入っているので、fname1の文字列の最後をヌル文字'\0'に置換

1.20: fname1で指定したファイルの先頭アドレスをファイルポインタ fp1 に読み込む

1.21: もしfp1がNULLだったときは、ファイルを開けなかったので、即座にプログラム終了

1.27: データファイル名を入力させ、fname2に格納

1.28: 入力させた文字列の最後にエンターキーが入っているので、fname2の文字列の最後をヌル文字'\0'に置換

1.30: fname2で指定したファイルの先頭アドレスをファイルポインタ fp2 に読み込む

1.31: もしfp1がNULLだったときは、ファイルを開けなかったので、即座にプログラム終了

1.37: id[9]を入力させる

1.39: fname2のファイルを1行ずつbuf2に読み込む。もし読み込み成功する限り以下を繰り返す

1.39: fname1のファイルを1行ずつ", "で区切り左側を配列gender、右側を配列heightsに読み込む

1.40: buf2からscanfで数値文字列を文字列としてidf[9]に読み込む

1.43: もしid[9]とidf[9]が等しかったとき、以下を実行

1.43: もしid[9]とidf[9]が等しい限り以下を行う

1.44: 変数gender_numにgender[i]を代入（iの宣言時i=1としてheights.csvの無関係な1行目を飛ばせるようにする）

1.45: 変数heightにheights[i]を代入

1.50: もしid[9]とidf[9]が等しくない限りi++とz++を実行

1.52: 変数zが14である限り文字列"No data"を出力

1.56: fname2のファイルを閉じる。閉じれないときは、即座にプログラム終了

1.61: fname1のファイルを閉じる。閉じれないときは、即座にプログラム終了

1.67: 変数id[9]を出力

1.67: もしgender_numが1のときは"Male"、2のときは"Female"と出力

1.73: 変数heightを出力

## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴

