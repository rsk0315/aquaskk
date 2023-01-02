// -*- C++ -*-

#ifndef MockInputSessionParameter_h
#define MockInputSessionParameter_h

#include "MockAnnotator.h"
#include "MockCandidateWindow.h"
#include "MockClipboard.h"
#include "MockConfig.h"
#include "MockDynamicCompletor.h"
#include "MockFrontEnd.h"
#include "MockMessenger.h"
#include "SKKInputSessionParameter.h"

class MockInputSessionParameter : public SKKInputSessionParameter {
    MockConfig config_;
    MockFrontEnd* frontend_;
    MockMessenger messenger_;
    MockClipboard clipboard_;
    MockCandidateWindow candidate_;
    MockAnnotator annotator_;
    MockDynamicCompletor completor_;

public:
    MockInputSessionParameter() : frontend_(new MockFrontEnd()) {}

    virtual SKKConfig* Config() { return &config_; }
    virtual SKKFrontEnd* FrontEnd() { return frontend_; }
    virtual SKKMessenger* Messenger() { return &messenger_; }
    virtual SKKClipboard* Clipboard() { return &clipboard_; }
    virtual SKKCandidateWindow* CandidateWindow() { return &candidate_; }
    virtual SKKAnnotator* Annotator() { return &annotator_; }
    virtual SKKDynamicCompletor* DynamicCompletor() { return &completor_; }

    SKKInputModeListener* Listener() { return frontend_; }
    TestResult& Result() { return *frontend_; }
    void SetSelectedString(const std::string& str) {
        frontend_->SetSelectedString(str);
    }
    void SetYankString(const std::string& str) { clipboard_.SetString(str); }
};

#endif
