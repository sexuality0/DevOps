# Report Linux DO1
## Part 1. Установка ОС
1. Дистрибутив Ubuntu Server
ubuntu-20.04-live-server-amd64.iso
скачиваем с сайта:<br>
https://www.ubuntu.com/download/server<br>
Устанавливаем в виртуальную машину VirtualBox.<br>
Чтобы узнать версию ОС, необходимо выполнить команду:<br>
`cat /etc/issue`<br>
![](./images/CatVerison.png)<br>

## Part 2. Создание пользователя
1. Для создания нового пользователя небходимо выполнить команду:<br>
`sudo useradd -G adm septimak_virtual`<br>
![](./images/img2.PNG)<br>
2. Проверяем нового созданного пользователя:<br>
`cat /etc/passwd | grep septimak_virtual`<br>
![](./images/mya.png)<br>
3. Проверяем к каким группам относится новый пользователь:<br>
`groups septimak_virtual`<br>
![](./images/img04.PNG)<br>

## Part 3. Настройка сети ОС
1. Задаем и проверяем новое имя машины:<br>
`sudo hostname user-1`<br>
![](./images/SmenaHostnameUser1.png)<br>
2. Задаем новую временную зону и проверяем изменения:<br>
`sudo timedatectl set-timezone Asia/Novosibirsk`<br>
`timedatectl`<br>
![](./images/LocalTimeNovosibirsk.png)<br>
3. Установили набор сетевых инструментов<br>
![](./images/img06.png)<br>
Вывели информацию о сетевых интерфейсах<br>
![](./images/ifConfig.png)<br>
`lo (loopback device) – виртуальный интерфейс, присутствующий по умолчанию в любом Linux. Он используется для отладки сетевых программ и запуска серверных приложений на локальной машине. С этим интерфейсом всегда связан адрес 127.0.0.1. У него есть dns-имя – localhost.`<br>
4. Получили ip от dhcp сервера<br>
`10.0.2.15`

      ![Alt text](./images/IPotDHCP.png "Optional Title")<br>

**DHCP - Dynamic Host Configuration Protocol**<br>
    `DHCP — сетевой протокол, позволяющий сетевым устройствам автоматически получать IP-адрес и другие параметры, необходимые для работы в сети TCP/IP.`<br>
  5. Узнали внешний IP-адрес<br>
       ![Alt text](./images//VneshniyIpaddress.png "Optional Title")<br>
     6. Узнали внутренний IP-адрес шлюза, он же ip-адрес по умолчанию<br>
    ![Alt text](./images/VnutrenniyIpPoUmolchaniy.png "Optional Title")<br>
7. Изменили файл /etc/netplan/*.yaml, применили изменения в netplan, перезагрузились<br>
![Alt text](./images/NastroikaIPGWDNS.png "Optional Title")<br>
![Alt text](./images/NewIPGWDNS.png "Optional Title")<br>
`Пишем sudo netplan apply a затем - `

![Alt text](./images/RebootDoPinga.png "Optional Title")<br>

8. Проверяем, что адреса соотсветствуют заданным в предыдущем пункте<br>
![](./images/ifConfig.png)<br>
9. Успешно пропинговали удаленные хосты  ya.ru<br>
![Alt text](./images/Ping4Packeta0Lossov.png "Optional Title")<br>
<br>

## Part 4. Обновление ОС
1. Обновляем системные пакеты:<br>
`sudo apt update`<br>
![](./images/ObnovlenieOC.png)<br>
`sudo apt upgrade`<br>
![](./images/UpdatingTime.png)<br>
![](./images/FullUpdateGotov.png)<br>

## Part 5. Использование команды sudo
* `Sudo — это утилита, предоставляющая привилегии root для выполнения административных операций в соответствии со своими настройками. Она позволяет легко контролировать доступ к важным приложениям в системе. По умолчанию, при установке Ubuntu первому пользователю (тому, который создаётся во время установки) предоставляются полные права на использование sudo. Т.е. фактически первый пользователь обладает той же свободой действий, что и root.`<br>

1. Выдаем права sudo для пользователя:<br>
`sudo usermod -aG sudo septimak_virtual`<br>
![](./images/DalSudoVtoromyCheliky.png)<br>
2. Для того, чтобы изменить hostname ОС от имени пользователя необходимо выполнить следующие команды:<br>
Проверяем измененный hostname:<br>
`su - septimak_virtual`<br>
![](./images/PereshelNaNextUser.png)<br>
`sudo hostname user-2`<br>
`hostname`<br>
![](./images/ChangedHostname2OnSeptimakVirtual.png)<br>


## Part 6. Установка и настройка службы времени
1. Настраиваем автоматическую синхронизацию времени:<br>
`sudo apt install ntpdate`<br>
![](./images/installNTPdate.png)<br>
`sudo apt install systemd-timesyncd`<br>
![](./images/SkachalNTP.png)<br>
`timedatectl show`<br>
![](./images/FullSynchronizedNTPwithtime.png)<br>

![](./images/img22.PNG)<br>
## Part 7. Установка и использование текстовых редакторов
1. Установить текстовые редакторы VIM (+ любые два по желанию NANO, MCEDIT, JOE и т.д.)  <br>
sudo apt install vim    <br>
sudo apt install nano    <br>
sudo apt install mcedit<br>
2. Используя каждый из трех выбранных редакторов, создайте файл test_X.txt, где X -- название редактора, в котором создан файл. Напишите в нём свой никнейм, закройте файл с сохранением изменений.
3. Используя каждый из трех выбранных редакторов, откройте файл на редактирование, отредактируйте файл, заменив никнейм на строку "21 School 21", закройте файл без сохранения изменений.
4. Используя каждый из трех выбранных редакторов, отредактируйте файл ещё раз (по аналогии с предыдущим пунктом), а затем освойте функции поиска по содержимому файла (слово) и замены слова на любое другое.
### VIM
1. ![](./images/installVim.png)
2. ![](./images/septimakINvim.png)
3. ![](./images/Red21SchoolVIM.png)
4. ![](./images/FIndWithVIM.png)
* vim test_vim.txt   
* Режим редактирования: i
* Выйти из режима редактирования: esc   
* Выход с охранением: :wq     
* Выход без сохранения: :q        
* Поиск: /<текст, который хотим найти>    
* Замена: :s/<что хотим изменить>/<на что хотим заменить>
### JOE
1. ![](./images/installJOE.png)
2. ![](./images/septimakINjoe.png)
3. ![](./images/Red21SchoolJOE.png)
4. ![](./images/FindWithJOE.png)
* joe test_joe.txt       
* Выход с охранением: Ctrl + K X
* Выход без сохранения: Ctrl + C      
* Поиск: Ctrl + K F
* Замена: Ctrl + T
### NANO
1.![](./images/installNano.png)    
2.![](./images/septimakINnano.png)     
3.![](./images/Red21SchoolNano.png)
4.![](./images/FindWithNano.png)
* nano test_nano.txt       
* Выход с охранением: CTRL + x, затем y, и  enter
* Выход без сохранения: CTRL + x, затем n       
* Поиск: CTRL + W, затем enter (alt + w для перехода к след. вхождению, ctrl + c  для преращения поиска)
* Замена: CTRL + \\ <что хотим изменить + enter> + <на что хотим заменить + enter> + A(для замены все вхождения) или y и n по отдельности

## Part 8. Установка и базовая настройка сервиса SSHD
1. Устанавливаем sshd, добавляем автостарт и запускаем:<br>
`sudo apt update`<br>

`sudo apt-get install ssh`<br>
![](./images/InstallSSH.png)<br>
`sudo apt install openssh-server`<br>
![](./images/InstallSSHserver.png)<br>
Если служба не активна, запустите ее вручную с помощью команды:<br>
`sudo systemctl enable ssh`<br>
![](./images/EnableAutoStart.png)<br>
`sudo systemctl start sshd`<br>
`systemctl status sshd`<br>
![](./images/ProverkaRabotiSSHD.png)<br>
Если в системе включен брандмауэр, обязательно откройте порт SSH:<br>   
`sudo ufw allow ssh`

2. Перенастраиваем службу sshd на порт 2022:<br>
`sudo nano /etc/ssh/sshd_config`<br>
![](./images/MenyaemPrtNa2022.png)<br>
`systemctl restart sshd`<br>
`reboot`<br>


![](./images/RebootAfterPs.png)<br>
![](./images/NahodimSSHDpsom.png)<br>

3. Используя команду ps, показать наличие процесса sshd:<br>
`Команда ps выдает информацию об активных процессах.`<br>
`-A, -e, (a) - выбрать все процессы`<br>
`-a - выбрать все процессы, кроме фоновых`<br>
`-d, (g) - выбрать все процессы, даже фоновые, кроме процессов сессий`<br>
`-N - выбрать все процессы кроме указанных`<br>
`-С - выбирать процессы по имени команды`<br>
`-G - выбрать процессы по ID группы`<br>
`-p, (p) - выбрать процессы PID`<br>
`-x заставляет ps отображать список всех процессов, которыми вы владеете`<br>
`-ppid - выбрать процессы по PID родительского процесса`<br>
`-s - выбрать процессы по ID сессии`<br>
`-t, (t) - выбрать процессы по tty`<br>
`-u, (U) - выбрать процессы пользователя`<br>
`r - просмотреть все работающие (running) процессы`<br>

4. Вывод команды netstat -tan:<br>
![](./images/PortPomenyalsaNa2022.png)<br>
* `Ключ -t отображает только TCP сокеты`<br>
* `Ключ -a отображает все сокеты (listening and non-listening)`<br>
* `Ключ -n отображает адреса и порты вместо имен`<br>
* `Proto показывает протокол, используемый сокетов`<br>
* `Recv-Q - количество байтов в очереди приема (ожидающих чтения) для сокета`<br>
* `Send-Q - количество байтов в очереди отправки (ожидающих отправки) для сокета`<br>
* `Local Address - локальный IP-адрес участвующий в соединении или связанный со службой, ожидающей входящие соединения`<br>
* `Foreign Address - внешний IP-адрес, участвующий в создании соединения`<br>
* `State - состояние сокета (LISTEN означает, что сокет находится в состоянии прослушивания и ожидает входящих соединений)`<br>
* `Если в качестве адреса отображается 0.0.0.0 , то это означает - "любой адрес", т.е в соединении могут использоваться все IP-адреса существующие на данном компьютере.`<br>

## Part 9. Установка и использование утилит top, htop
1. Выполняем команду:<br>
`sudo top`<br>
![](./images/InstallTop.png)<br>
![](./images/FullTOP.png)<br>
`uptime: 7min`<br>
`количество авторизованных пользователей: 1 user`<br>
`общая загрузка системы: 0,00, 0,02, 0,00 (загрузка системы за последние 1, 5 и 15 минут)`<br>
`общее количество процессов: Tasks: 105 total, 1 running, 104 sleeping, 0 stopped, 0 zombie`<br>
`загрузка cpu: 0,2 us, 0,0 sy, 0,0 ni,99,8 id, 0,0 wa, 0,0 hi, 0,0 si, 0,0 st`<br>
`PID процесса занимающего больше всего памяти - 1 (top -o %MEM);`<br>
`PID процесса, занимающего больше всего процессорного времени - 1111 (top -o %CPU);`<br>

2. Выполняем команду:<br>
`sudo htop`<br>
![](./images/installHTOP.png)<br>
2.1. Сортировка htop по PID:<br>
![](./images/SortPID.png)<br>
2.2. Сортировка htop по PERCENT_CPU:<br>
![](./images/SortCPU.png)<br>
2.3. Сортировка htop по PERCENT_MEM:<br>
![](./images/SortMEM.png)<br>
2.4. Сортировка htop по TIME:<br>
![](./images/SortTIME.png)<br>
2.5. Фильтр для процесса sshd:<br>
![](./images/FilterBysshd.png)<br>
2.6. Фильтр для процесса syslog:<br>
![](./images/SyslogWithSearch.png)<br>
2.7. С добавленным выводом hostname, clock и uptime<br>
![](./images/HostnameClockUptime.png)<br>
## Part 10. Использование утилиты fdisk
1. Выполняем команду:<br>
`sudo fdisk -l`<br>
![](./images/SudoFdiskL.png)<br>
`Название жесткого диска: Disk model: VBOX HARDDISK`<br>
![](./images/NazvanieDiska.png)<br>
`Размер жесткого диска: 25 GiB`<br>
![](./images/SectorsInVHDD.png)<br>
`Количество секторов: 52428800 sectors`<br>
2. Выполняем команду:<br>
`sudo free -h`<br>
`Флаг -h выводит информацию в гигабайтах`<br>
![](./images/SwapVHDD.png)<br>
`Размер swap:  2.2 GiB`<br>
## Part 11. Использование утилиты df
1. Узнаем информацию о дисковом пространстве:<br>
`sudo df / df`<br>
![](./images/STartDF.png)<br>
`Размер раздела: 11758760`<br>
`Размер занятого пространства: 5031092`<br>
`Размер свободного пространства: 6108560`<br>
`Процент использования: 46%`<br>
`Единица измерения: 1килобайт`<br>
2. Запустить команду df -Th<br>
`sudo df -Th`<br>
![](./images/DF-THKorn.png)<br>
`Размер раздела: 12G`<br>
`Размер занятого пространства: 4,8G`<br>
`Размер свободного пространства: 5,9G`<br>
`Процент использования: 46%`<br>
`Тип файловой системы раздела: ext4`<br>
## Part 12. Использование утилиты du
1. Вывод размера папок /home, /var, /var/log<br>
`sudo du -s /home `<br>
`sudo du -s /var `<br>
`sudo du -s /var/log -`<br>
![](./images/DuHomeVarVarlog.png)<br>
2. Вывод размера всего содержимого в /var/log:<br>
`sudo du -sh /var/log/* `<br>
![](./images/VarlogZvezdaVKonce.png)<br>

## Part 13. Установка и использование утилиты ncdu
1. Вывод размера папок /home, /var, /var/log с помощью утилиты ncdu:<br>
* устанавливаем утилиту ncdu: `sudo apt install ncdu`<br>
![](./images/InstallNCDU.png)<br>
* выполняем команды:<br>
`sudo ncdu /home`<br>

![](./images/NCDUhome.png)<br>
`sudo ncdu /var`<br>

![](./images/NCDUVar.png)<br>
`sudo ncdu /var/log`<br>

![](./images/NCDUVarLOG.png)<br>
## Part 14. Работа с системными журналами
1. Поиск последней успешной авторизации, имени пользователя и метода входа в систему:<br>
`cat /var/log/auth.log | grep 'session opened'`<br>
![](./images/LOGSSSSS.png)<br>
`Время авторизации - Jul 17 20:08:01`<br>
`Имя пользователя - septimak`<br>
`Метод входа в систему - sudo: pam_unix(sudo:session)`<br>
2. Перезапуск службы sshd:<br>
![](./images/RestartSSHd.png)<br>
`vim /var/log/syslog | grep ssh`<br>
3. Поиск лога с сообщением о рестарте sshd:<br>
![](./images/grepSSSH.png)<br>

## Part 15. Использование планировщика заданий CRON
1. Используя планировщик заданий, запустить команду uptime через каждые 2 минуты:<br>
`crontab -e`<br>
![](./images/ScreptForCron.png)<br>
2. Найти в системных журналах строчки (минимум две в заданном временном диапазоне) о выполнении:<br>
![](./images/UptimeRazV2Minutes.png)<br>
3. Вывести на экран список текущих заданий для CRON:<br>
`crontab -l`<br>
![](./images/VseZadachiCron.png)<br>
4. Удалить все задания из планировщика заданий:<br>
`crontab -r`<br>
![](./images/RemoveCronQuests.png)<br>
5. Список текущих задач:<br>
`crontab -l`<br>
![](./images/last.png)<br>