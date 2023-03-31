# C++_project

Aplikacja zarządzająca zamówieniami w restauracji w języku C++ stworzona w grópie (4 osoby) w ramach modulu Podstawy programowania (CDV).

Aplikacja wyświetlia opcje: 
- Zamkniecie programu;
- Złożenie zamówienia;
- Historia zamówień;
- Historia zamówień dla danego dnia;

Złożenie zamówienia:
Aplikacja wczytuje menu restauracji. Dane są zapisane w folderze menu. Każda pozycja w menu ma swoją nazwę i cenę. Dodatkowo każdy plik w tym folderze to kategoria. Np. pizza.txt zawiera jedynie nazwy różnych rodzajów pizzy wraz z ich cenami.

Aplikacja wyświetla kompletne menu podzielone na kategorie.

Użytkownik podaje numery pozycji jakie powinny być dodane do zamówienia.

Każda pozycja z menu może być dodana N razy, przy czym w jednym zamówieniu nie może być więcej niż 10 dań.

Po wprowadzeniu zamówienia użytkownik może:
- Zaakceptować zamówienie;
- Usunąć pozycje z zamówienia / Dodać pozycje do zamówienia.

Zaakceptowane zamówienie zostaje zapisane w pliku dhistory.txt.

Historia zamówień:
Historia może być wczytywana z pliku.
Pozycja zawiera datę zamówienia, unikalne id, nazwę potrawy, jej cenę i ilość, kolumnę z całkowitą kwotą zamówienia.
Historia zamówień  wyświetla pozycje od najnowszej do najstarszej.
Historia zamówień dla danego dnia wyświetla zamówienia z dnia wybranego przez użytkownika.
