# SZKIELETOWA SIEĆ ŚWIATŁOWODOWA
Kolejny krok za nami, ale nie przestajemy. Aby robota poszła sprawnie i bez zakłóceń potrzebujemy dobrej sieci, dlatego stawiamy światłowodową sieć szkieletową. Jeśli przesył odbywa się tylko poprzez tę sieć, to opóźnienia komunikacyjne są pomijalne. Dzięki temu sieć rozwija się bardzo dynamicznie. Musisz napisać program, który odpowie czy dane dwa adresy IP łączy sieć czysto światłowodowa. Ma być czyste światło, czaisz? Mamy do połączenia dwa fakty:
jeden z naszych dostarczy nam numery IP pomiędzy którymi koniecznie trzeba zbudować bezpośrednie połączenie [czyli operacje typu B …]
trzeba też zbadać które węzły łączą się czysto światłowodowo, choć niekoniecznie bezpośrednio [czyli operacje typu T …]

### DANE WEJŚCIOWE
Wejście składa się z wierszy, z których każdy zawiera informację o budowie nowego połączenia lub zapytanie o istnienie połączenia.

Informacja o budowie nowego łącza ma postać:
B  IP1  IP2

gdzie IP1 i IP2 to adresy IP (w formacie czterech liczb z zakresu 1..255 oddzielonych kropkami), pomiędzy którymi powstaje łącze. Na początku działania programu sieć nie zawiera żadnych łączy.

Zapytanie o istnienie połączenia światłowodowego ma natomiast postać:
T  IP1  IP2
Dane wejściowe kończą się wraz z końcem pliku.

### DANE WYJŚCIOWE
Na każde zapytanie należy wypisać w osobnym wierszu T lub N w zależności, czy dane dwa adresy IP łączy sieć światłowodowa, czy też nie.

### PRZYKŁADY
Wejście

B 100.100.100.1 100.100.100.2
B 100.100.100.1 100.100.100.3
B 100.100.100.10 100.100.100.11
T 100.100.100.1 100.100.100.3
T 100.100.100.10 100.100.100.2
T 100.100.100.10 100.100.100.11
B 100.100.100.11 100.100.100.2
T 100.100.100.10 100.100.100.3
T 100.100.100.100 100.100.100.103
Wyjście

T
N
T
T
N