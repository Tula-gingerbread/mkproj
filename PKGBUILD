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

source=(
    "file://${startdir}/main.cpp"
    "file://${startdir}/include/gitignores.hpp"
    "file://${startdir}/include/hello_world.hpp"
    "file://${startdir}/include/mkproj.cpp"
    "file://${startdir}/include/mkproj.hpp"
    "file://${startdir}/include/prepare.hpp"
    "file://${startdir}/include/string_utils.cpp"
    "file://${startdir}/include/string_utils.hpp"
)

b2sums=(
    "5c6a66d102fc2f6953dbccd40f3c1046e8c11f9bca10a901a040643041e86c6e8a8846c44986c5c2ed297b2b2947d5091be26e0d5048bd94768849e425471791"
    "4c40df59f71665665187a206b54cea5988d552ae1c6812264cff6ea3bff6be6b1077e17d96b2e8ab79c0a5ad66b3dc40e20b3177e5a58ef0670616b4c69cf134"
    "2b848ec5903addea79c905a882a608697f26d16771b1485b2ef381bba1dd93bbf61f054ae185cb78c782a62e636008b9a09a76170684c6f2218012a0cb8995af"
    "5b6141cf9e725b3f2cfc12fcb6f67d130f83c655dab2801a4959134da0ee7ad328809d2315bc025dc82b94c4caa55843f74c923db52386837b637dbb9e9d8551"
    "0b12f26e1a85317b6028db7c1fb876a4a4b663619fa8d75bdefc305abca8d576a83b5ee7bdd33ee9277819b914ab3bdccbc3c83108bb0bf2ae7db9130ab8a4e0"
    "832d6614e836e1fedf65b51772ce85a4871719ae563a379b0822ff74891666b1a5864531de6716d71177831abe9fd94e85836a2d8df4db336cfb75b66e9f1eee"
    "3eeba35dd9d80dd0fc6f29faa6d474002695b6f26eedb215177db2e0e66e661aaff6f749e4e17c70e4d7e95fc25e81219f7a813e81216ec0c91a203c8f53acef"
    "e1bf4d1ff43dfb596c0960e53edfeb37f02f745ec1b0b87339916975d85a0f4fa65ed7a6b5d6d6fd6eafbafa4dd07b2ac0fde55ef461a68994b36253be28ea4b"
)

replaces=("pymkproj")

build() {
    cd ..
    g++ main.cpp include/* -o "${srcdir}/mkproj.run" -march=native -static
}

package() {
    install -Dm755 mkproj.run "${pkgdir}/usr/bin/mkproj"
}
