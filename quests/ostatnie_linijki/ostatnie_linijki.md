# OSTATNIE LINIJKI!
Prawie to mamy, ostatnie zadanie – skupmy się! Pamiętasz, jak w dawnych czasach ludzie mieli takie marne rozrywki jak gierki w kolorowe kulki? Dzięki naszym wszystkim akcjom wypadowym dowiedzieliśmy się, że jakiś totalny freak zabezpieczył sprzęt, na którym nam zależy właśnie w taki sposób. Gierka logiczna, rozumiesz? Musisz dać radę, im zrobisz to lepiej, tym większa szansa na wygraną!

Gra logiczna JawBreaker polega na usuwaniu przylegających kulek o tym samym kolorze z prostokątnej planszy. Kulki mogą być usunięte wyłącznie kiedy stykają się bokami i tworzą grupę przynajmniej dwuelementową. Liczba zdobywanych punktów zależy od rozmiaru usuwanej grupy. Liczba punktów przyznawana za usunięcie grupy N elementowej jest równa N(N-1). Przykładowo usunięcie pary kulek premiowane jest dwoma punktami, natomiast usunięcie 8-elementowej grupy jest warte 56 (8 * 7) punktów.

Na kulki rozmieszczone na planszy działa grawitacja – po usunięciu grupy wszystkie kulki, które były powyżej opadają pionowo w dół wypełniając puste miejsca.


Gra kończy się w momencie, w którym na planszy nie ma już ani jednej grupy, która można usunąć. Twoim zadaniem jest zdobycie jak największej liczby punktów dla podanej planszy Jawbreakera.

Przykładowa plansza wygląda następująco:


Na rysunku zaznaczona jest siedmioelementowa grupa, której usunięcie jest premiowane 42 punktami. Po usunięciu wskazanej grupy plansza wygląda następująco:


Przed przystąpieniem do rozwiązywania warto zagrać w grę w sposób interaktywny. Gra dostępna pod linkiem zawiera dodatkową zasadę, którą należy pominąć rozwiązując zadanie. Mianowicie w interaktywnej grze po usunięciu całej kolumny kulki zostają przyciągnięte do strony prawej. Takiej zasady nie stosujemy w tym zadaniu.

### DANE WEJŚCIOWE
W pierwszej linii znajduje się liczba przypadków testowych   . W dalszej części znajdują się kolejne przypadki testowe. Pojedynczy przypadek testowy zaczyna się od pojedynczej linii zawierających trzy liczby całkowite:

  – liczba wierszy planszy

  – liczba kolumn planszy

  – liczba różnych kolorów jakie moga mieć kulki na planszy
Następnie H linii zawierających W liczb rozdzielonych spacjami. Każda z liczb należy do przedziału   i oznacza kolor kulki.

### DANE WYJŚCIOWE
Dla każdego przypadku testowego należy wypisać “Y” jeśli chce się podać rozwiązanie lub “N” jeśli chce się pominąć dany przypadek testowy. W przypadku wypisania “Y“, w kolejnych liniach należy podać rozwiązanie. Rozwiązaniem jest pewna liczba linii, z których każda zawiera dwie całkowite liczby:x i y Te liczby definiują odpowiednio numer wiersza ( zatem  ) oraz numer kolumny (zatem  ). Współrzędne określone są względem lewego górnego narożnika pola gry (który ma współrzędne   ) . Po wypisaniu ostatniej pary należy wypisać linię zawierającą napis “-1 -1“.


Twoje rozwiązanie otrzyma status “błędna odpowiedź” jeśli wykonasz jeden z następujących ruchów:

współrzędne wskażą punkt poza polem gry,
współrzędne na których nie ma kulki,
współrzędne wskazujące grupę jednoelementową.

### SPOSÓB PUNKTACJI
Ocena końcowa jest obliczona jako 
 
  , gdzie points jest sumą wszystkich punktów zdobytych we wszystkich rozwiązanych grach znormalizowanych w następujący sposób:
 
gdzie B oznacza liczbę punktów bazowych obliczanych w sposób podany w treści zadania (tzn.   punktów za usunięcie grupy N – elementowej), C oznacza liczbę kolorów a H, W. oznaczają wymiary planszy.

### PRZYKŁADY
Wejście

1
4 4 3
0 0 1 1
1 1 2 2
0 1 2 0
0 1 1 2
Wyjście

Y
1 0
1 0
3 2
-1 -1

### WYJAŚNIENIA
Początkowy stan planszy:
0 0 1 1
1 1 2 2
0 1 2 0
0 1 1 2
Po usunięciu grupy pięciu jedynek wskazanej przez punkt (1, 0) (pierwszy wiersz, zerowa kolumna):
0 0 1 1                  . . . 1
X x 2 2        ->        0 . 1 2
0 x 2 0                  0 . 2 0
0 x x 2                  0 0 2 2
Następnie rozwiązanie ponownie wskazuje na punkt (1, 0) prowadząc do usunięcia czterech zer:
. . . 1                  . . . 1
X . 1 2        ->        . . 1 2
x . 2 0                  . . 2 0
x x 2 2                  . . 2 2
Kolejny ruch wskazuje na punkt (3,2) który należy do trzyelementowej grupy złożonej z dwójek:
. . . 1                  . . . .
. . 1 2        ->        . . . 1
. . x 0                  . . . 2
. . X x                  . . 1 0
Na planszy nie została już ani jedna grupa, rozwiązanie mimo to wskazuje, że był to ostatni ruch poprzez wypisanie “-1 -1”. W tym przypadku punktacja jest następująca:
  ,