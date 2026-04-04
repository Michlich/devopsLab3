FROM debian:12
# Установка зависимостей
RUN apt-get update && apt-get install -y \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*
# Копирование .deb‑пакета из артефакта
COPY programm_1.0_all.deb /app/programm_1.0_all.deb
COPY main.cpp /app/main.cpp
COPY Makefile /app/Makefile
# Установка .deb‑пакета
RUN dpkg -i /app/programm_1.0_all.deb || \
    (apt-get update && apt-get install -f -y && dpkg -i /app/programm_1.0_all.deb)
# Очистка
RUN rm /app/programm_1.0_all.deb
# Рабочая директория
WORKDIR /app
# Запуск приложения с параметром успешного завершения
CMD ["/usr/bin/your-program", "--success-exit"]
