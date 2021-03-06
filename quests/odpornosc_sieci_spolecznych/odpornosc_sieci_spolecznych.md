# ODPORNOŚĆ SIECI SPOŁECZNYCH
Trackerzy z naszej ekipy, Alice i Rob, potrzebują Twojej pomocy. Bardzo zainteresowali się sieciami społecznymi i mają kilka pomysłów jak możemy je wykorzystać przy naszym zleceniu.

– “Al, wierzysz w zalecenia dawane Ci przez kolesi, których nie znasz osobiście?” – spytał Robert
– “Nie.” – odpowiedziała Alicja
– “Ale jak twój ziomek daje Ci tipa, to raczej mu ufasz?” – drążył Rob
– “Dokładnie, wtedy to co innego” – odpowiedziała Alice
– “Właśnie, ja mam tak samo. A gdyby ktoś chciał wpłynąć na całą sieć społeczną?” – zapytał Rob
– “Jeśli w danej sieci istnieje osoba, powiedzmy A, która jest w prywatnej relacji z całą resztą, to wystarczy kontrolować konto tej osoby, żeby móc wpływać na całą sieć.” – kontynuował Robert
– “Czyli odporność sieci na takie ataki zależy od jej struktury?” – zauważyła Alice
– “Totalnie! I dokładnie to musimy rozgryźć.” – potwierdził Rob

Kilka godzin później oboje zgodzili się na następujący model: dla sieci społecznej o n członkach i symetrycznej relacji przyjaźni (tzn. jeśli A jest przyjacielem B to również B jest przyjacielem A. Dodatkowo, każdemu członkowi A przypisujemy dodatnią liczbę całkowitą W(A). Liczbę W(A) interpretujemy jako koszt przejęcia kontroli nad kontem członka A.

Zadanie jakie postawili sobie nasi trackerzy polega na znalezieniu takiego zbioru członków sieci społecznej D, że każdy członek sieci społecznej albo należy do tego zbioru albo przyjaźni się z kimś kto do tego zbioru należy. Dodatkowo Alice i Rob chcieliby znaleźć taki zbiór D, dla którego koszt przejęcia kont należących do tego zbioru jest możliwie najmniejszy.

Pomóż im to ogarnąć, a będziemy o krok bliżej do udziału w ważnym dla nas konkursie!

### DANE WEJŚCIOWE
W pierwszej linii danych wejściowych znajduje się liczba całkowita nbędąca liczbą członków sieci społecznej. W kolejnych n liniach znajdują się dane w następującym formacie:
To znaczy najpierw nazwa i-tego członka sieci będąca ciągiem co najwyżej 15 znaków. Następnie liczba całkowita  będąca kosztem przejęcia konta tego członka. Kolejna linia danych wejściowych zawiera liczbę całkowitą m będącą liczbą relacji przyjaźni między członkami sieci społecznej. W kolejnych m liniach znajdują się dane w następującym formacie:
To znaczy nazwy dwóch różnych członków o których wiadomo, że są przyjaciółmi.

### DANE WYJŚCIOWE
W pierwszej linii danych wyjściowych wypisz liczbę d będącą liczbą członków w wyznaczonym zbiorze D. Następnie w kolejnych d liniach wypisz nazwy członków zbioru D.

Na koniec, w ostatniej linii danych wejściowych wypisz jedną liczbę będącą sumarycznym kosztem przejęcia wszystkich kont ze zbioru D.

### SPOSÓB PUNKTACJI
Liczba punktów jaką uzyska Twoje rozwiązanie zostanie obliczone jak

 , gdzie S jest sumarycznym kosztem przejęcia wszystkich kont sieci społecznej a  jest sumarycznym kosztem przejęcia wszystkich kont ze zbioru D.

Wynik końcowy jest czterokrotnością sumy wyników uzyskanych przez Twój program dla wszystkich poprawnie rozwiązanych przypadków testowych.

Zadanie zostaje uznane za rozwiązane jeśli Twój program rozwiąże przynajmniej jedne przypadek testowy i jako wynik końcowy uzyska ponad 20 puntów.

### PRZYKŁADY
Wejście

5
Robert 12
Julia 23
Adam 1
Carol 10
Daniel 4
5
Robert Julia
Robert Carol
Adam Robert
Daniel Adam
Daniel Julia
Wyjście

2
Daniel
Carol
14

### LICZBA PUNKTÓW
Rozwiąznie podane w przykładzie jest poprawne i uzyskałoby

 punktów. Wkład tego przypadku testowego w końcowy wynik byłby wtedy równy  punktów.

### PRZYPADKI TESTOWE
t	n	m	l
1	100	99	2s
2	100	101	2s
3	100	105	2s
4	100	114	2s
5	100	130	2s