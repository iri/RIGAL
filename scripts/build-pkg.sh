cd ../src
make fullclean
make
cd ../scripts

mkdir -p /usr/include/rigal/

fpm -t deb -s dir \
    --name rigal --version 4.45.1 --description "Rigal is compiler construction language" \
    -a amd64 \
    --license "MIT" \
    --depends bash \
    -m "Ingars Ribners <ram3a12@gmail.com>" \
    --before-install preinstall.sh \
    --after-remove postremove.sh \
    ../bin/rc=/usr/bin/rc \
    ../bin/ic=/usr/bin/ic \
    ../bin/v=/usr/bin/v \
    ../bin/rig_lint=/usr/bin/rig_lint \
    ../bin/anrig=/usr/bin/anrig \
    ../bin/genrigd=/usr/bin/genrigd \
    ../lib/riglib.a=/usr/lib/riglib.a \
    ../include/globrig.h=/usr/include/rigal/globrig.h \
    ../docs/doc-src/rigal.1=/usr/share/man/man1/rigal.1 \
    .

mv ./*.deb ../distr/
ls -l ../distr/
