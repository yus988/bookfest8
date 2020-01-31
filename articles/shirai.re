= Virtual CastとHapbeatを使った国際双方向アバター触覚ライブの開発
#@# である調→ですます調のほうがいい感じがするので統一

えっ、GithubのURLから直接編集できるんですか？便利すぎる！
iPadのブラウザでも行けそうです！
ありがとうございます！！


== VTuberライブエンタメ技術に求められる研究開発

=== SIGGRAPH Real-Time Live!について

SIGGRAPH Real-Time Live!とは、SIGGRAPH内で開催されるリアルタイムのライブデモセッションです。
そもそも「SIGGRAPH」は ACM (Association for Computing Machinery, ニューヨークに本部のある計算機科学の国際学会) の分科会
「Special Interest Group on Computer GRAPHics」の略で、発足は1967年、カンファレンスとしては1974年から続く長い歴史を持ちます。
参加者規模も2万人～4万人といったも大きな国際会議なので「世界最大のコンピュータグラフィックスとインタラクション技術における国際会議」と呼んでよいと思います。

@<href>{https://www.siggraph.org/}

夏は北米で7月ごろ開催されます。特に2年に一度はロサンゼルスで開催しています。
ハリウッドの映画産業を擁するロサンゼルスでの開催が参加者にとっても便利ですし、カルフォルニア州による誘致の働きかけもあるそうです。
SIGGRAPH自体の参加者数は近年20,000人規模で推移していますが、やはりロサンゼルスでの開催が最も参加者が多いです。
かつてのピークから半減した理由の一つとして、2008年からは冬場にSIGGRAPH Asiaとして、アジアでの開催がされております。
中国・韓国・日本からの参加者・発表者は多く、SIGGRAPH Asiaはシンガポールを拠点に毎年巡回しています。
日本では過去、横浜（2009年）、神戸（2015年）、東京（2018年）に開催されており、直近では2019年に初のAPAC地域としてオーストラリア・ブリスベン、さらに2021年には東京での開催も予定されています。

さて、SIGGRAPHは映画産業と研究者のためだけのイベントではありません。
ゲームやライブエンタテインメント、最先端のインタラクティブ技術なども数多く扱われています。
筆者は1997年の初参加から、SIGGRAPHにはほぼ毎年参加しているのですが、この23年でゲーム産業は大きく成長し、マーケット向けにはE3、開発者向けにはGDCとエキスポの住み分けが進みました。
また関連分野のエキスポとしては、ラスベガスで1月に開催される「CES」は家電とIoT、テキサス州オースティンで3月に開催される「SXSW」は広告メディアとゲーム、音楽イベントとサービスのフィールド実験が特徴です。
GDCで扱ういわゆる「ゲーム技術」も、かつてのようにリアルタイムグラフィックス技術だけが重視されるのではなく、ネットワーキングや設計、インフラ、大規模なチームマネジメントといった技術に広がってきています。

一方でSIGGRAPH内では学術論文発表や見本市はそのままに、従来の主力であったアニメーション・フェスティバルといった映像作品の上映会は年々規模が縮小し、新技術のデモ、特にVRのコンテンツや技術デモは大きな規模で、かつ人気の展示となっています。
その中でもリアルタイムグラフィックスのデモとしては一番大きなセッションとして「Real Time Live!」が2010年に誕生しています。
これはリアルタイムグラフィックスを中心とするライブデモによるショーケースイベントです。
NVIDIAのようなGPUメーカーのR&D成果の発表や研究者による技術デモ以外に、ゲーム産業における具体的なタイトルの開発手法や、映画産業におけるPreVizといったライブプレビュー技術など、
各社がアクターを使ったり、熱のこもったプレゼンなどを行い、
いわゆる「技術デモ」というよりは派手さも求められるショーになります。
会場も数千人が入る超巨大会場で、1発表あたりの持ち時間は10分以下。
一方で、来場者が歓声をあげたり拍手したり、といった反応もライブで感じられる注目のセッションです。

=== GREE VR Studio Lab の挑戦
GREE VR Studio Labは2018年の東京での「Real Time Live!」においては★

== Virtual CastとHapbeatを使った国際双方向アバター触覚ライブの開発
=== 実現したい機能

//image[SA19RTL-map][東京と開催地のオーストラリア・ブリスベンは7,154km離れている。そしてVirtual Castの推奨環境は4K動画並み。]

=== Virtual CastとVCI

=== Hapbeatを使用した国際双方向触覚ライブ

=== 会場音声分析からのギフト送信

=== node.js を使ったVirtual Castの拡張

== そのほかの技術

=== M5Stackによる触覚の可視化


== パフォーマンス
=== シナリオの設計
=== シナリオを作りこみ
=== リハーサルをする
=== ダンスを練習する

== 当日に起きたこと
=== 国際リモートライブのためのリハーサル
=== 機材がクソ重い
=== 音声品質と遠のくゴール
=== 不測のトラブル

== 今後に向けて
=== フィードバック
=== 音響の改善
=== シナリオの改善

== 謝辞


====[column] Azure環境で技術書を書く

本稿はVSCodeのブラウザ版で書いています。

@<href>{https://online.visualstudio.com/}

最初はWindowsにDocker環境を構築しようとしてジタバタいたのですが、執筆のためだけにあれこれインストールするのに疲れました…Azureのアカウントが必要ですが、無料枠で十分な感じです。
このブラウザ版VSCode（正式名称はVisual Studio Online）にはターミナルもbash環境もあり、Docker環境も作れるようなのですが、あれこれインストールするならいっそ
Visual Studio Code環境だけでも作れそうな気がします。

そもそも本書は樋口さんらにより Github上にRe:VIEW で執筆環境を構築されておりますので、Github上で自分のブランチのpublishをしてプルリクエストさえ出せれば、あとはcircleciがRe:VIEW→TeX→PDFまでコンパイルしてくれちゃいます。

画像ファイルの追加なども Visual Studio Onlineなら簡単にアップロードしてリポジトリに追加できてしまいますので、学生さんの卒論等にも便利なのではないかと思いました。
自分の研究室ではかつて、卒論集を Cloud LaTeX や Github で管理していたのと、自分の書籍はXMLで書いていた時期もあったので技術書典部をきっかけにいろいろ勉強になりました！

====[/column]

