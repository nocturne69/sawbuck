// Copyright 2012 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef SYZYGY_PDB_PDB_CONSTANTS_H_
#define SYZYGY_PDB_PDB_CONSTANTS_H_

#include "base/basictypes.h"

namespace pdb {

// The index of the Pdb old directory stream.
const size_t kPdbOldDirectoryStream = 0;

// The index of the Pdb info header stream.
const size_t kPdbHeaderInfoStream = 1;

// The version we've observed in the Pdb info header.
const uint32 kPdbCurrentVersion = 20000404;

// The signature we've observed in the section contribs substream of the Pdb Dbi
// stream.
const uint32 kPdbDbiSectionContribsSignature = 0xF12EBA2D;

// The signature we've observed for the name tables of the Pdb.
const uint32 kPdbNameTableSignature = 0xEFFEEFFE;

// The version we've observed for the name tables of the Pdb.
const uint32 kPdbNameTableVersion = 1;

// The index of the Tpi (Type info) stream.
const size_t kTpiStream = 2;

// The index of the Dbi info stream.
const size_t kDbiStream = 3;

// This is the magic value found at the start of all MSF v7.00 files.
const size_t kPdbHeaderMagicStringSize = 32;
extern const uint8 kPdbHeaderMagicString[kPdbHeaderMagicStringSize];

// The maximum number of root pages in the Multi-Stream Format (MSF) header.
// See http://code.google.com/p/pdbparser/wiki/MSF_Format
const uint32 kPdbMaxDirPages = 73;

// We typically see 1024-byte page sizes generated by the MSVS linker, but this
// in turn has a maximum file size of 1GB. The compiler generates PDBs with
// 4KB page sizes which has a maximum file size of 2GB. Presumably this could be
// any power of 2 in size, but we've only ever seen 1024 and 4096. This is
// found in bytes 32 through 35 (little endian) of any PDB file. We use 4KB
// pages so that we can handle PDBs up to 2GB without problems (we regularly
// exceed 1GB when dealing with Chrome).
const uint32 kPdbPageSize = 4096;

// The named PDB stream containing the history of Syzygy transformations applied
// to an image. This consists of a sequence of Metadata objects.
extern const char kSyzygyHistoryStreamName[];

// The version of the Syzygy history stream. This needs to be incremented
// whenever the format of the stream has changed.
const uint32 kSyzygyHistoryStreamVersion = 0;

// The named PDB stream containing the serialized BlockGraph of an image.
extern const char kSyzygyBlockGraphStreamName[];

// The version of the Syzygy BlockGraph data stream. This needs to be
// incremented whenever the format of the stream has changed.
const uint32 kSyzygyBlockGraphStreamVersion = 1;

}  // namespace pdb

#endif  // SYZYGY_PDB_PDB_CONSTANTS_H_