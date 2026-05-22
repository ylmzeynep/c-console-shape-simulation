# c-console-shape-simulation
Ödev İçeriği 
1. Ödevde yaptığınız Java ödevini C dili ile Nesne Yönelimli benzetim kullanılarak tekrar yapınız. 
Program çalıştığı gibi kullanıcıdan ilk etapta oyunun çalışacağı tur sayısını almalıdır. Daha sonra 
aşağıdaki formata uygun sayıları tek seferde alacaktır. Sayılar birer boşluk ile ayrılmış iki basamaklı 
sayılardır. 
18 25 79 37 62 86 17 50 
Burada geliştirilecek oyunda, şehre bağlı ilçeler, ilçeye bağlı mahalleler ve mahallede yaşayan kişiler 
olacaktır. 
Yukarıda girilen sayıların şu şekilde bir anlamı bulunmaktadır. 
18 sayısı bir şehirdeki nüfusu gösteriyor. Dolayısıyla yukarıda oyunu 8 il olarak başlatmış anlamına 
gelmektedir. 
Sayıların onlar basamağı bu şehre bağlı kaç adet ilçe olduğu göstermektedir. Yani 18 sayısının onlar 
basamağı 1 olduğu için şehre bağlı sadece 1 ilçe bulunduğu anlamına gelmektedir. 
Sayıların birler basamağı ise mahalle sayısını temsil etmektedir. Mahalle sayısı ilçelere eşit oranda 
bölüştürülecektir. 18 sayısında sadece bir ilçe olduğu için 8 mahalle bu ilçeye bağlı olacaktır. 
Ama örneğin 25 sayısında 2 ilçe ve 5 mahalle var. 5 sayısı ikiye tam bölüştürülemeyeceği için en yakın 
bölünebilen sayıya arttırılacaktır. Yani 6 olacaktır. Dolayısıyla yeni sayı 26 olmuştur. Her ilçede 3 
mahalle bulunacaktır. 
Yine 79 sayısı örnek alınacak olursa 7 ilçeye 9 mahalle bölüştürülemiyor. Bu durumda onlar basamağı 
değişmeden birler basamağı yine 1 sayısından başlayarak 9’a kadar ilerleyecektir. 7 sayısı tam 
bölüneceği için her ilçeye bir mahalle düşecek ve sayımız 77 olacaktır.  
Sayıların kendisi de ildeki toplam nüfusu temsil etmektedir. Mahallere eşit oranda dağıtılacaktır. 
Örneğin 18 sayısında ilin nüfusu 18 ama 18 8’e tam bölünemediği için yine bölünebilecek en yakın 
sayıya arttırılacaktır. Yani 24. Dolayısıyla ilk şehrin son nüfusu 24 olacaktır. Ama bu yeni sayı ilçe ve 
mahalle sayısının değişimine neden olmayacaktır.  
İlk şehrin son durumu: bir ilçe, bu ilçeye bağlı 8 mahalle ve her mahallede yaşayan 3 kişi olacaktır. 
Oyunda her turun sonunda ekranda aşağıdaki şekilde şehir nüfusları gösterilmelidir. Her satıra 5 şehir 
gelecek şekilde olmalıdır. Yukarıdaki kullanıcının girmiş olduğu sayı dizilimi düşünüldüğünde ilk tura 
başlamadan nüfus durumu aşağıdaki gibi olacaktır.  
[24]-[30]-[77]-[45]-[66] 
[88]-[21]-[55] 
İlk turun sonunda şehirlerdeki nüfus durumu ve ekran gösterimi aşağıdaki gibi olacaktır. 
[144]-[90]-[1078]-[405]-[792] 
[1408]-[63]-[550] 
Önemli:  Bir turun sonunda herhangi bir ilin nüfusu 4 basamaklı olursa şehir yarıya bölünecek ve bir 
yarısı ile yeni bir şehir oluşturulacaktır. Bu şehre yeni bir isim verilecek (Faker yardımıyla) ama İlçe 
ona bağlı mahalleler ve mahalledeki kişiler diğer şehirden taşınacaktır. Bölünecek şehir ilçe sayısı tam 
bölünecek bu sayı çift sayı ise tam bölünecek ama tek sayısı ise yeni şehirde bir eksik olarak 
oluşturulacaktır. Yani 6 ilçe varsa 3 ilçe yeni şehre taşınacak, 5 ilçe varsa 2 ilçe yeni şehre taşınacak 3 
ilçe eski şehirde kalacaktır. İlçe taşınması bağlı olduğu mahaller ve kişiler ile birlikte olacaktır. Oluşan 
yeni şehir ekran gösteriminde en sona yerleştirilecektir. 
Yukarıdaki örnekte bir turun sonuna gelinmiş ve iki şehir nüfusu 4 basamaklı olmuştur. Bunlar 
bölünecektir. Yeni son durum aşağıda verilmiştir. 
[144]-[90]-[616]-[405]-[792] 
[704]-[63]-[550]-[462]-[704] 
Bir şehirdeki mahallelerde nüfus artış oranı nüfusun geldiği son sayıdaki birler ve onlar basamağındaki 
sayıların toplamı ile belirlenecektir. Yani 18 örneği en son 24 sayısına gelmişti. Dolayısıyla 2+4=6 bu 
şehre bağlı her mahalledeki nüfus artış oranı 6 kat olacaktır. 6x3=18 dolayısıyla bu turun bitiminde bu 
şehrin toplam nüfusu 18x8=144 olacaktır. Her mahallede 3 kişi ve toplam 8 mahalle bulunmaktaydı. 
Bu şehir artık ekranda 144 olarak görünmelidir. Turlar peş peşe hızlı bir şekilde bu mantıkla devam 
edecek ve sürekli şehirlerin nüfusları ekranda görünecektir. Ekran her turun sonunda temizlenmelidir. 
Bir şehirdeki basamak adedi artsa bile nüfus artış oranı her zaman birler ve onlar basamağındaki 
sayıların toplamı ile belirlenecektir. Eğer toplam sıfır olursa o şehirdeki her mahallede nüfus 1 kişi 
artacaktır. 
Her turun sonunda kişilerin yaşları 1 artmalıdır. Kişilerin yaşları oyun başlarken 0-50 arası rastgele 
atanacaktır. 
Turlarda bölünme aşamasında değerin (ilçe sayısı veya mahalle) 1 olması durumunda yeni 
oluşturulacak şehirde de 1 yeni (ilçe veya mahalle) oluşturulacak ama nüfus yarıya bölünüp 
taşınacaktır. 
Oyunda tutulması gereken bilgiler: 
Şehir: Adı, nüfusu 
İlçe: Adı, nüfusu 
Mahalle: Adı, nüfusu, yaşayan kişiler 
Kişi: 
İsim/soyisim (Örnek Beyza Sarı) 
Yaş (Örnek: 35) 
ID (int olacak ve oyunun tamamında aynı ID’ye sahip iki kişi olmayacak.) 
Oyunun sonunda ekrana şehirlerin nüfusları tekrar yazılacak ve ekranda kullanıcıdan satır ve sütun 
istenecektir. Satır ve sütunlar sıfırdan başlamaktadır.  
[144]-[90]-[616]-[405]-[792] 
[704]-[63]-[550]-[462]-[704] 
Örneğin yukarıdaki şekli ile son turun bittiği düşünülürse ve kullanıcı satır için 1, sütun için 2 girerse 
550 nüfusa sahip şehir ekrana yazdırılacaktır. 
İlgili hücredeki şehir aşağıdaki formatta ekrana yazdırılacaktır. Daha sonra kullanıcı herhangi bir tuşa 
bastığında oyun kapanacaktır. 
İsim ve sayılar örnek olarak verilmiştir. 550 sayısını tam olarak sağlamamaktadır. Kişilerin 
listelenmesinde ID – isim soyisim – Yaş sırası kullanılacaktır. 
Şehir: Ankara - Nüfus: 550 
İlçe: Gölbaşı – Nüfus: 105 
Mahalle: İncek – Nüfus: 24 
Kişiler: 
105 - Ahmet Kabak – 28 
103 – Zeki Yas – 60 
…. Şeklinde devam edecek İncek mahallesindeki tüm kişiler listelenecektir. 
… Şeklinde devam edecek Gölbaşı ilçesindeki tüm mahaller listelenecektir. 
İlçe: Çankaya – Nüfus: 259 
Mahalle: Namık Kemal – Nüfus: 65 
Kişiler: 
…. Şeklinde devam edecek Namık Kemal mahallesindeki tüm kişiler listelenecektir. 
… Şeklinde devam edecek Çankaya ilçesindeki tüm mahaller listelenecektir. 
Önemli: Yukarıda belirtilen bilgilerin tamamı Java Faker (https://dius.github.io/java-faker) 
kütüphanesi kullanılarak oluşturulacaktır. Sallama isimler ve bilgiler olmayacaktır. Bunlar bir dosya 
yapısına en az 10.000 adet olacak şekilde yazılacak C dilinde bu dosya yapısı kullanılarak bilgiler elde 
edilecektir. Dosya yapısı öğrencinin kendisine kalmıştır. Dilediği gibi tasarlayabilir. 
En son tur bitince ekranda program duracaktır. Program sonlanmamalıdır.  Burada görüntülenmek 
istenen il kullanıcıdan satır ve sütun mantığı ile istenecektir. 
Programda modülerliğe dikkat edilmeli ve tek sorumluluk prensibi ile yapılar tasarlanmalıdır. 
Minimum beklenen yapılar aşağıda verilmiştir. Önemli: İlk ödevden farklı olarak burada Yerlesim 
yapısı tasarlanacak ve Şehir, İlçe, Mahalle yapıları bu Yerlesim yapısından kalıtım alıyormuş gibi 
benzetim yapılacaktır. 
Main Yapısı 
Oyun Yapısı 
Yerlesim Yapısı 
Şehir Yapısı 
İlçe Yapısı 
Mahalle Yapısı 
Kişi Yapısı 
Program şehir sayısı fazla olacak şekilde denenmelidir.  
Her yapının başlık ve kaynak dosyaları ayrı bir şekilde ve başlık dosyasında metot gövdesi olmayacak 
bir şekilde tasarlanmalıdır. Klasör hiyerarşisi ve make dosyası derste gösterildiği şekilde olmak 
zorundadır. Bütün çağrımlar fonksiyon göstericisi yardımıyla yapılmalıdır. 
Önemli: Ödevi yaparken aşağıdaki kaynaklar yardımcı olacaktır. 
Nesne yönelimli benzetim için https://youtu.be/yMHGt2Bcsts 
Kalıtım ve Soyut Sınıf benzetimi için https://youtu.be/ov_GudbL1qo 
