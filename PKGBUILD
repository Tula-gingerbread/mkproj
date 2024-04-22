pkgname="mkproj"
pkgver=1.0
pkgrel=2
pkgdesc="Make project from template"
arch=("x86_64")
url="https://github.com/Tula-gingerbread/mkproj"
license=("GPL3")

makedepends=("gcc")
optdepends=("gcc: C and C++ compiler"
            "clang: C and C++ compiler"
            "python: https://python.org")

source=("file://${startdir}/sums.b2")
b2sums=("5f8cf77b1ea9091fa5270d7660868687a152d59f1549106aad678d7ae04395398fd23b962c44968020243ecc32373f0d8326d7b936613a692b0b42e86477dc7b")

build() {
    cd "${startdir}"

    # I did this check because I don't want to write an inconvenient source=(...) and then b2sums=(...)
    b2sum --check --strict sums.b2
    if [ "$?" != "0" ]; then
        echo "BUILD: Failed to verify the integrity of the files!"
        exit
    fi

    g++ main.cpp include/*.hpp -o "${srcdir}/mkproj.run" -march=native -static
}

package() {
    install -Dm755 mkproj.run "${pkgdir}/usr/bin/mkproj"
}
