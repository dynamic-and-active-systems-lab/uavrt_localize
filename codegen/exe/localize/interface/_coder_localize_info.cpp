//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: _coder_localize_info.cpp
//
// MATLAB Coder version            : 5.6
// C/C++ source code generated on  : 03-Jul-2023 15:32:45
//

// Include Files
#include "_coder_localize_info.h"
#include "emlrt.h"
#include "tmwtypes.h"

// Function Declarations
static const mxArray *emlrtMexFcnResolvedFunctionsInfo();

// Function Definitions
//
// Arguments    : void
// Return Type  : const mxArray *
//
static const mxArray *emlrtMexFcnResolvedFunctionsInfo()
{
  const mxArray *nameCaptureInfo;
  const char_T *data[9]{
      "789ced594f4fe34614372b7617552a4562db5b4fe5502dda58fc1344ea2524210e594268"
      "021b5ab130898764f078269d1907924fb0dacb4a155291566a0ffd10"
      "fd1a3df4d04b2f95fa09b8eca5ea3a3843620b2ba8864184bccbf8f937f6efcd1bebf7de"
      "24da5876634cd3b449cdb3b3e7def869d79fea8e8f34bf05f1b1eef8",
      "34e04b7bac8dfb9e93f8bbee58a544c013e13904d8f0f24993da8800224aad06d418e414"
      "37a179811c220c4bc886c57e27dff1ecb53ee8d2e9409deb641d56ad"
      "a2636bacce7b11e27ee7321f7f86ac77fc9af9e0015f0bcc93f8f7e93d7d9b43c6759bd7"
      "c12164fa4b546180b5f424a68e591494811ad437094c31d4842ff294",
      "893a6424c1509b12b04ddc9b8c23e1cedf4ca5f70b2f13bb996f37b7f329dd014d26f631"
      "ad028cda50971731dbb7ce46c4754e06fce03a25ce20302b1030446a"
      "55deecdd3f88c83f1ef07bfc1e52ad03d61fc787887c3f86f2f97165fbea73814094ec3b"
      "0261aefb33deddf68179ffec9a79088ebdf91317e3f9d22fa64a3ee3",
      "3f2ba6924fda5df19d84bcefbadff1e7217c53019c1dd573165fafb7568f0b4b5b89d5e5"
      "6cbed0ee8ba3308067501c5a88afeafd233df02ceaf7343d200f12af"
      "41d1a9f79daa8d11816e9cdc17c741c43854d7839f42f9fcf8ddefff1599773f0255fab5"
      "88df2bad077fff73f4954a3e69f7b51e7c11c23715c09b6b30615476",
      "6abbf1c5b9dc724198b5ecbab3363cf54059df9f2d27f7666c2030a8304ac58c2e28c515"
      "7aa27bf774130820dca30fd7abd484354874012a0e064c9fedce9845"
      "eed1891180f5d9ce1417b89cd170350408a83701cbbb672a9e4276a0ef7f13719d5f0f58"
      "a7c4bd586332d4d845a4b16ea0b1a47bfa43c471652daafe072d2c2e",
      "6992eff7ffc927df8f06f049dcddeffcaded772f8db2ac2bd3a1dfbe1c7bad924fda43e1"
      "53a5ebe5344f2fe0924137e61756e23b96035b478991ae3fb8df73c2"
      "f23a1518b1ab4994cc43c005e92ce1a6faf727a1fc1e6252a782e1cdf5efa7a17c7efcee"
      "fbf760c6bd8d57a54bd313bf2aeddfbffb595b51c9276dd8757e6769",
      "a3d82e8394850a49e33857b64a73f1e3ccf0e8fc480f3c5355079a885421112d137101dc"
      "cb511db8ed7d0f665c6d1d283d555b07fe5afb6652259fb461af03d5"
      "5ad9386a707c588ca7cd5dc3b0d7733fe45687a70e3c947e3feaf7f26cc03a252ee90f19"
      "b5bbff22f0fe380e22c6a15aefcf42f9fcf8ddebfd55998fd9aaf469",
      "c150abf7e7a57f6755f2491b76bdcf72d1489b4e6637518897b0d86c6331b7901ee9fd7d"
      "d37bd57d3d2466832222eeabcedfbfbe5e665c6d5f7f9a51abf36f3f"
      "f9e3b94a3e69c3aef316cb2caec0ad57c71ca30d2b6b58a2b6dc18029dff0870adcf05",
      ""};
  nameCaptureInfo = nullptr;
  emlrtNameCaptureMxArrayR2016a(&data[0], 10928U, &nameCaptureInfo);
  return nameCaptureInfo;
}

//
// Arguments    : void
// Return Type  : mxArray *
//
mxArray *emlrtMexFcnProperties()
{
  mxArray *xEntryPoints;
  mxArray *xInputs;
  mxArray *xResult;
  const char_T *propFieldName[7]{
      "Version",      "ResolvedFunctions", "Checksum",    "EntryPoints",
      "CoverageInfo", "IsPolymorphic",     "PropertyList"};
  const char_T *epFieldName[6]{
      "Name",           "NumberOfInputs", "NumberOfOutputs",
      "ConstantInputs", "FullPath",       "TimeStamp"};
  xEntryPoints =
      emlrtCreateStructMatrix(1, 1, 6, (const char_T **)&epFieldName[0]);
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("localize"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs",
                emlrtMxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(
      xEntryPoints, 0, "FullPath",
      emlrtMxCreateString("/Users/mshafer/Library/CloudStorage/"
                          "OneDrive-NorthernArizonaUniversity/CODE_PLAYGROUND/"
                          "uavrt_localize/localize.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp",
                emlrtMxCreateDoubleScalar(739070.63071759255));
  xResult =
      emlrtCreateStructMatrix(1, 1, 7, (const char_T **)&propFieldName[0]);
  emlrtSetField(xResult, 0, "Version",
                emlrtMxCreateString("9.14.0.2206163 (R2023a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions",
                (mxArray *)emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "Checksum",
                emlrtMxCreateString("wCyJj1rQq9QzdshaoqdRAD"));
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

//
// File trailer for _coder_localize_info.cpp
//
// [EOF]
//
