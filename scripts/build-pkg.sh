cd ../src
make
cd ../scripts

fpm -t deb -s dir \
    --name rigal --version 4.45.1 --description "Rigal is compiler construction language" \
    -a amd64 \
    --license "MIT" \
    --depends bash \
    -m "Ingars Ribners <ram3a12@gmail.com>" \
    ../bin/rc=/usr/bin/rc \
    ../bin/ic=/usr/bin/ic \
    ../bin/v=/usr/bin/v \
    ../bin/rig_lint=/usr/bin/rig_lint \
    ../docs/doc-src/rigal.1=/usr/share/man/man1/rigal.1 \
    .

mv ./*.deb ../distr/
ls -l ../distr/
