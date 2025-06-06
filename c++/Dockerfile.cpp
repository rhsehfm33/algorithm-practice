FROM gcc:latest

RUN echo 'alias mk=". /home/c++/maker.sh"' >> /root/.bashrc && \
    echo 'alias push="/home/c++/pusher.sh"' >> /root/.bashrc && \
    echo 'alias judge="diff <(./sol < 1)"' >> /root/.bashrc

RUN apt-get update && apt-get install -y gdb