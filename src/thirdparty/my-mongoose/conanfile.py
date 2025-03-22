from conan import ConanFile
from conan.tools.files import get, copy
import os

class MongooseConan(ConanFile):
    name = "mongoose"
    version = "7.11"  # 可以根据 Mongoose 的版本号调整
    license = "GPL-2.0"
    url = "https://github.com/cesanta/mongoose"
    description = "Mongoose Embedded Web Server Library"
    settings = "os", "compiler", "build_type", "arch"

    def source(self):
        # 从 GitHub 下载 Mongoose 源码
        get(self, f"{self.url}/archive/refs/heads/master.zip")

    def build(self):
        # Mongoose 是一个单文件库，通常不需要构建
        pass

    def package(self):
        # 将 mongoose.h 和 mongoose.c 复制到包中
        copy(self, "*.h", dst=os.path.join(self.package_folder, "include"), src="mongoose-master")
        copy(self, "*.c", dst=os.path.join(self.package_folder, "src"), src="mongoose-master")

    def package_info(self):
        # 定义库的信息
        self.cpp_info.libs = ["mongoose"]

class MyProjectConan(ConanFile):
    requires = "mongoose/7.11@user/stable"
    generators = "CMakeDeps", "CMakeToolchain"