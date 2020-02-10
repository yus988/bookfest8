= Virtual CastとHapbeatを使った国際双方向アバター触覚ライブの開発
#@# である調→ですます調のほうがいい感じがするので統一
#@# 参考文献が本文中でうまく参照できていない感じだけど、本文が冗長になることを避けたいのでできるだけ引用で済ます方針。

== VTuberライブエンタメ技術に求められる研究開発

GREE VR Studio Labは2018年からグリーグループに設置されたVTuber（バーチャルユーチューバー）やVRエンターテインメントシステムにおける研究開発、企業間連携、研究交流発信事業を担当する研究開発組織です。
現在、グリーが注力している分野のひとつであるVTuber事業は、アニメーションやゲーム、ライブ配信など、多岐にわたるエンターテインメント技術が必要とされる分野です。

それらを構成する技術要素はゲーム開発におけるリアルタイム3Dグラフィックスや、モーションキャプチャー、サーバー技術などがあり、加えて、ライブ・エンターテインメントに適したモーション生成や、演者支援、ディスプレイ技術、インタラクション技術、人工知能応用、キャラクター設計、エモーション分析、視聴者文化の調査分析など多岐にわたっています。このような新しい分野の研究開発は既存の企業内R&D手法だけでは問題分析や課題解決が難しく、産学連携やスタートアップ企業との連携などを通して、最先端の技術や手法を実装していくことが世界的なスタンダードとなりつつあります。

グリーグループでライブエンターテインメントを推進するWright Flyer Live Entertainment（以下、WFLE）には、主にプロダクション事業、プラットフォーム事業、ソリューション事業があり、そのプラットフォーム事業の中にもPresence Technology Group（以下PT）が、スタジオ技術を中心にVTuberコンテンツ制作やプラットフォーム開発を実施しています。

そうした中、VR Studio Labは、VRゲームなどを企画、開発、配信してきたGREE VR Studioと併設され、
（1） VTuber関連技術のR&D促進、（2） 異業種R&D連携強化、（3） 業界振興・イノベーション型人材の支援発掘や育成、
の3つを基本方針として活動しています。
WFLEが開発するVTuber専用ライブ配信プラットフォーム「REALITY」開発チームのもつ知見や経験を、日本国内の大学・企業・研究機関などの研究者や学生等とのコミュニケーションを通じて共有し、知財開発およびスピード感のある社会実装、品質向上、技術発信に貢献しています。

//image[WFLEPT-GVRS][WFLE PTとGREE VR Studioの位置づけ]

具体的には長期スパンのR&D、知財創出、アライアンス、新技術の調査選定、国際展開、普及啓蒙事業、社会実装を通した実験などがあります。
（本稿で扱いませんが）千葉大教育学部付属小学校でのVTuberを使った実験授業 @<bib>{CSR20190322}や、大学でのプログラミング講義向けアバターの教育向け応用（引用@<bib>{RexIVA}）、また新技術の開発系では無料ボイチェンサービス「転声こえうらない」（@<href>{https://vr.gree.net/lab/vc/}）のリリースや、ライブエンターテインメントの研究所らしくTwitter@<href>{https://twitter.com/vrstudiolab,@VRStudioLab}やYouTubeチャンネル @<href>{http://j.mp/VRSYT} でもライブイベントや資料映像を発信しております、SlideShareでも資料を公開しておりますので（@<href>{https://www.slideshare.net/vrstudiolab/}）、ご興味ありましたらご購読いただけると幸いです。

=== SIGGRAPH Real-Time Live!について

本稿ではVTuber技術、特に次世代型のライブエンターテインメントで使えそうな技術や裏話について紹介していきたいと思います。
特に2019年11月にオーストラリアと日本を接続して実施した「SIGGRAPH Real-Time Live!」について、構成する技術について紹介していきます。

SIGGRAPH Real-Time Live!とは、SIGGRAPH内で開催されるリアルタイムのライブデモセッションです。
そもそも「SIGGRAPH」は ACM（Association for Computing Machinery, ニューヨークに本部のある計算機科学の国際学会）の分科会
「Special Interest Group on Computer GRAPHics」の略で、発足は1967年、カンファレンスとしては1974年から続く長い歴史を持ちます。
参加者規模も2万人～4万人といったも大きな国際会議なので「世界最大のコンピュータグラフィックスとインタラクション技術における国際会議」と呼んでよいと思います（@<href>{https://www.siggraph.org/}）。

SIGGRAPH年に一度の大会は、夏は北米で7月ごろ開催されます。特に2年に一度はロサンゼルスで開催しています。
ハリウッドの映画産業を擁するロサンゼルスでの開催が参加者にとっても便利ですし、カルフォルニア州による誘致の働きかけもあるそうです。
SIGGRAPH自体の参加者数は近年20,000人規模で推移していますが、やはりロサンゼルスでの開催がもっとも参加者が多いです。
かつてのピークから半減した理由のひとつとして、2008年からは冬場にSIGGRAPH Asia（以下、SA）として、アジアでの開催がされております。
もともとSIGGRAPH自体は中国・韓国・日本からの参加者・発表者も多く、SAは北米版と異なり、実施会社がドイツ系のケルンメッセ、そのシンガポール支社が中心に運営していることもありシンガポールを拠点に巡回しています。
すでにSAだけでも12年の歴史をもち、日本では過去、横浜（2009年）、神戸（2015年）、東京（2018年）に開催されており、直近では2019年に初のAPAC地域としてオーストラリア・ブリスベン、さらに2021年には東京での開催も予定されています。

さて、SIGGRAPHは映画産業と研究者のためだけのイベントではありません。
ゲームやライブエンタテインメント、最先端のインタラクティブ技術なども数多く扱われています。
筆者は1997年の初参加から、SIGGRAPHにはほぼ毎年参加しているのですが、この23年でゲーム産業は大きく成長し、マーケット向けにはE3、開発者向けにはGDCとエキスポの住み分けが進みました。
また関連分野のエキスポとしては、ラスベガスで1月に開催される「CES」は家電とIoT、テキサス州オースティンで3月に開催される「SXSW」は広告メディアとゲーム、音楽イベントとサービスのフィールド実験が特徴です。
GDCで扱ういわゆる「ゲーム技術」も、かつてのようにリアルタイムグラフィックス技術だけが重視されるのではなく、ネットワーキングや設計、インフラ、大規模なチームマネジメントといった技術に広がってきています。

一方でSIGGRAPH内では学術論文発表や見本市はそのままに、従来の主力であったアニメーション・フェスティバルといった映像作品の上映会は年々規模が縮小し、新技術のデモ、特にVRのコンテンツや技術デモは大きな規模で、かつ人気の展示となっています。
その中でもリアルタイムグラフィックスのデモとしては一番大きなセッションとして「Real Time Live!」（以下、RTL）が2010年に誕生しています。
これはリアルタイムグラフィックスを中心とするライブデモによるショーケースイベントです。
NVIDIAのようなGPUメーカーのR&D成果の発表や研究者による技術デモ以外に、ゲーム産業における具体的なタイトルの開発手法や、映画産業におけるPreVizといったライブプレビュー技術など、
各社がアクターを使ったり、熱のこもったプレゼンなどを行い、
いわゆる「技術デモ」というよりは派手さも求められるショーになります。
会場も数千人が入る超巨大会場で、1発表あたりの持ち時間は10分以下。
一方で、来場者が歓声をあげたり拍手したり、といった反応もライブで感じられる注目のセッションです。

=== GREE VR Studio Lab の挑戦（SA18RTL）
2018年の東京、SA18RTLは東京国際フォーラム「Hall C」という客席1,500人のホールで開催されました。この回ははじめてのSAにおけるRTLでしたので、上演プログラムは公募ベースではなくチェア（長谷川勇 氏，Luminous Productions／スクウェア・エニックス）による推薦ベースで実施されました。
日本からはスクエニやバンナムさんがR&D成果として、リアルタイムグラフィックスやAIによる対話的アニメーションのデモをする中、
GREE VR Studio Labは、はじめてのリアルタイムライブデモ「“REALITY: Be yourself you want to be” VTuber and presence technologies in live entertainment which can make interact between smartphone and virtual live characters（REALITY：「なりたい自分で生きていく」スマートフォンとバーチャルライブキャラクター間でやり取りできるVTuberとライブエンターテイメントのプレゼンス技術）」を発表しました @<bib>{SA18RTL}。
この発表はVR Studio LabとWFLEに加えて、ニュージーランドでモーションセンサーに仕える新素材を開発しているStretchSense社と、イギリスでソフトウェアによるモーションキャプチャー補完ミドルウェアを開発しているIKINEMA社と共同で実施しました。シナリオはすべて日本語＋英語バイリンガルで構築し、ラボディレクターである白井が今居＝リアリテ＝レアというキャラクターを演じ、iPhoneXによる表情モーションキャプチャーと特殊表情の可能性@<bib>{CCSE2019}、StretchSense社によるグローブ、UnrealEngine4による統合されたリアルタイムキャラクターアニメーションと、IKINEMA社による女性アクターと、リアルタイム・アニメーション・クリーニング・パイプライン、さらに新規でキャラクター「IKINEMA Aya」もデザインし、ダンスシーンもあり、けっこう大変でしたが得るものも大きな挑戦でした。
海外メディアからも取材や事後レポートがあり、現在もVR Studio LabのYouTubeでは人気のコンテンツになっています（@<href>{https://www.youtube.com/watch?v=zj2fe4A87GA}）。
なお、IKINEMA社は本件に関してプレスリリースを発行しています@<bib>{SA18RTL-IKINEMA}、しかしその半年後にはAppleに買収されてしまいましたので、世の中なかなかうまくいかないなあというところです。

#@# 2つの画像を合体させる予定
#@# //image[SA18-2355][SIGGRAPH ASIA 2018 TokyoでのReal-Time Live!の様子（SA公式提供）][scale=0.5]{
//image[SA18RTL][SIGGRAPH ASIA 2018 TokyoでのReal-Time Live!の様子（SIGGRAPH ASIA 公式提供）][scale=1.0]{
//}

=={a-label} Virtual CastとHapbeatを使った国際双方向アバター触覚ライブの開発

SA18RTLに続き、夏のSIGGRAPH2019においては、世界でのVTuber業界を再定義するべく「Virtual Beings World」というイベントを主催しました。
この中でGREE VR Studio Labは「World VTuber Showcase」というティザー動画コンテスト（@<href>{http://j.mp/WVS19}）を開催し、世界中から集まった22作の中からNTTドコモ「直感×アルゴリズム♪」をグランプリとして選出、VTuber文化のアンバサダーになれる権利として任命し、2019年11月にオーストラリアで開催されるSA19RTLにおけるコラボレーションのきっかけになりました@<bib>{VRON20190809}。

//image[S18VBW][SIGGRAPH 2018 で開催した「Virtual Beings World」の様子]{
//}

以上のような経緯から、SA19RTLにおいては、NTTドコモ副島義貴Pとイクスアール株式会社COO小池健輔氏、そしてVR Studio Labのインターンであり、東京工業大学発ベンチャー企業「Hapbeat合同会社」の代表でもある山崎勇祐さんと共著する形で企画提案をエントリーし、採択されました（@<href>{https://sa2019.siggraph.org/attend/real-time-live/session/111}）@<bib>{VRON20191119}。
タイトルは「Global Bidirectional Remote Haptic Live Entertainment by Virtual Beings (VTuberによるグローバルな双方向触覚ライブ)」で、「生アニメ」として人気の「直感アルゴリズム」とコラボすることになりました。
最終的なキャストとしては「直感アルゴリズム」のKilinさん（法元明菜さん）＆Xiさん（岩井映美里さん）が日本語と中国語を担当、そして英語担当として先述のWorld VTuber Showcaseでご縁のあった「お米アイドルMaiプリンセス」からミルキークイーンさんが参加することとなりました。


//image[SA19RTL-keyvisual][NTTドコモ副島Pのご協力により制作したキービジュアル]

=== 実現したい機能
#@# https://docs.google.com/presentation/d/1IosX_76FQ8Fi4ewnXgXh5uGrb83492zZMgIc7kjINuc/edit#slide=id.p6
#@# https://docs.google.com/presentation/d/1MnfQwyAcq4JnD1lZKzVyksAS9ieWsNxJvo6msbVW-KQ/edit#slide=id.g78f914e51a_1_0
#@# https://twitter.com/o_ob/status/1193913152716460033
VTuberによるグローバルな双方向触覚ライブ国際双方向触覚ライブ実験します

//image[SA19RTL-map][東京と開催地のオーストラリア・ブリスベンは7,154km離れている。そしてVirtual Castの推奨環境は4K動画並み。]

=== Virtual CastとVCI
VCIスクリプトはLua言語を使って書きます。
Unityをインストールして

https://virtualcast.jp/wiki/doku.php?id=vci:script:luatutorial
=== Hapbeatを使用した国際双方向触覚ライブ

=== 会場音声分析からのギフト送信

=== node.js を使ったVirtual Castの拡張

== その他の技術

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
#@# Matt AI - Speech Driven Digital Human with Emotions http://sa2019.conference-program.com/presentation/?id=real_106&sess=sess230 Jingxiang Li, et al. Tencent Technology Company Limited

== 今後に向けて
=== フィードバック
=== 音響の改善
=== シナリオの改善

== 謝辞
 SA19RTL ふりかえり ミルキークイーンさん/尾車Roseいのりさん
いつも元気で知的で英語シナリオの監修までやっていただいたミルキーさん。
本当にありがとうございました。

我々がなぜバーチャルビーイング（virtual being）なのか?という本質的な問 いについての深いシナリオまでできていたのですが、 残念ながら本番は声が元気すぎてマイクが死んでしまったものと推測しま す。今後、再挑戦する機会を是非とも作りたい! ぜひご一緒できましたら幸いです。
リンリンさん/法元明菜さん いつもよく気がつく努力家なリンリン/法元明菜さん。作って頂いた振り付け がとてもよく、徹夜で練習しまくりました。本番では音が飛んでいたのに踊 り続けられたのはこの特訓のおかげ!そして自己紹介パートのステキなイラ ストありがとうございました!
シーさん/岩井映美里さん いろんなご都合で本番直前のみの絡みとなり「いつもマイペースで何を考え ているか分からないところがあるよ~」という情報だけは頂いていたので実 はちょっぴり不安があったのですが、そんなことは杞憂でした。本当に声もキレイだし、芯がしっかりした人物なのだと感じました。特に最後のダンスシ ーン!会場のミュージックがトラブルで切れており、しかもバーチャル内で はそのトラブルがわからない状態だったのに、最後まで歌い続けて踊りもし っかり...会場は何が起きているのか、これがライブなのか!とわかり手拍子 から拍手の渦...今思い出しても泣きそうになります。
スタッフの皆様/おわりに
チェアの皆さんや他のReal-Time Live!発表者にもインタビューしてみたので すが、やっぱり会場をもっとも沸かせたのはウチの発表!新開発の会場熱気分析 システムもみごとにメーター振り切っていました。会場投票が無かったのは

 残念!トロフィー持って帰りたかった!くやしい! でも音声トラブルがあってシナリオがしっかり聞いてもらえなかったのも事実だし、審査員賞を取ったパフォーマンスもホント凄かった!これは是非と も学びたいやつです。 というわけで次はの挑戦は夏のSIGGRAPH（ワシントンD.C. 8/19-23）で会場 投票一位を目指して頑張るか、中国ライブかな...同じことは二度とやらない のがラボのポリシーでもあるので、技術的チャレンジも盛り込んでがんばっていきたいと思います!


====[column] Azure環境で技術書を書く

本稿はVSCodeのブラウザ版で書いています。

@<href>{https://online.visualstudio.com/}

最初はWindowsにDocker環境を構築しようとしてジタバタいたのですが、執筆のためだけにあれこれインストールするのに疲れました…Azureのアカウントが必要ですが、無料枠で十分な感じです。
このブラウザ版VSCode（正式名称はVisual Studio Online）にはターミナルもbash環境もあり、Docker環境も作れるようなのですが、あれこれインストールするならいっそ
Visual Studio Code環境だけでも作れそうな気がします。

そもそも本書は樋口さんらにより Github上にRe:VIEW で執筆環境を構築されておりますので、Github上で自分のブランチのpublishをしてプルリクエストさえ出せれば、あとはcircleciがRe:VIEW→TeX→PDFまでコンパイルしてくれちゃいます。

画像ファイルの追加なども Visual Studio Onlineなら簡単にアップロードしてリポジトリに追加できてしまいますので、学生さんの卒論等にも便利なのではないかと思いました。
自分の研究室ではかつて、卒論集を Cloud LaTeX や Github で管理していたのと、自分の書籍はXMLで書いていた時期もあったので技術書典部をきっかけにいろいろ勉強になりました！

えっ、GithubのURLから直接編集できるんですか？便利すぎる！
iPadのブラウザでも行けそうです！最近のiPadOSはZIPファイルもスンナリ解凍できるし…これは結構快適な技術書ライフが送れそうです。
樋口さん 環境構築ありがとうございます！！

====[/column]

