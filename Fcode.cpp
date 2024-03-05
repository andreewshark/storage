 if(developerAreaOffset) {
            if(developerAreaOffset < sizeof(Implementation::TgaHeader)) {
                Error{} << "Trade::TgaImporter::image2D(): TGA 2 developer area offset" << developerAreaOffset << "overlaps with file header";
                return {};
            }
            if(developerAreaOffset > _in.size() - sizeof(Implementation::TgaFooter)) {
                Error{} << "Trade::TgaImporter::image2D(): TGA 2 developer area offset" << developerAreaOffset << "out of range for" << _in.size() << "bytes and a" << sizeof(Implementation::TgaFooter) << Debug::nospace << "-byte file footer";
                return {};
            }

            if(!extensionOffset)
                srcPixels = srcPixels.prefix(_in.data() + developerAreaOffset);
            else if(developerAreaOffset < extensionOffset) {
                Error{} << "Trade::TgaImporter::image2D(): TGA 2 developer area offset" << developerAreaOffset << "overlaps with extensions at" << extensionOffset << "bytes";
                return {};
            }
        }
    }
}
template<> inline Vector3ub swizzle(const Vector3ub& value) {
    return Math::gather<'b', 'g', 'r'>(value);
}
template<> inline Vector4ub swizzle(const Vector4ub& value) {
    return Math::gather<'b', 'g', 'r', 'a'>(value);
}
//yes
