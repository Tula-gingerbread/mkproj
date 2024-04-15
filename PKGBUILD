pkgname="mkproj"
pkgver=1.0
pkgrel=1
pkgdesc="Make project from template"
arch=("x86_64")
url="https://github.com/Tula-gingerbread/mkproj"
license=("GPL3")
makedepends=("gcc")
optdepends=("gcc: C and C++ compiler"
            "clang: C and C++ compiler"
            "python")
replaces=("pymkproj")

build() {
    g++ "main.cpp" "include/*" -o "mkproj.run" -march=native -static
}

package() {
    install -Dm755 mkproj.run "${pkgdir}/usr/bin/mkproj"
}
