// Copyright (c) 2014 GitHub, Inc. All rights reserved.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef ATOM_BROWSER_WEB_VIEW_WEB_VIEW_RENDERER_STATE_H_
#define ATOM_BROWSER_WEB_VIEW_WEB_VIEW_RENDERER_STATE_H_

#include <map>
#include <string>
#include <utility>

#include "base/memory/singleton.h"

namespace atom {

class WebViewManager;

// This class keeps track of <webview> renderer state for use on the IO thread.
// All methods should be called on the IO thread.
class WebViewRendererState {
 public:
  struct WebViewInfo {
    int guest_instance_id;
    bool node_integration;
  };

  static WebViewRendererState* GetInstance();

  // Looks up the information for the embedder <webview> for a given render
  // view, if one exists. Called on the IO thread.
  bool GetInfo(int guest_process_id, WebViewInfo* webview_info);

  // Returns true if the given renderer is used by webviews.
  bool IsGuest(int render_process_id);

 private:
  friend class WebViewManager;
  friend struct DefaultSingletonTraits<WebViewRendererState>;

  typedef std::map<int, WebViewInfo> WebViewInfoMap;

  WebViewRendererState();
  ~WebViewRendererState();

  // Adds or removes a <webview> guest render process from the set.
  void AddGuest(int render_process_id, const WebViewInfo& webview_info);
  void RemoveGuest(int render_process_id);

  WebViewInfoMap webview_info_map_;

  DISALLOW_COPY_AND_ASSIGN(WebViewRendererState);
};

}  // namespace atom

#endif  // ATOM_BROWSER_WEB_VIEW_WEB_VIEW_RENDERER_STATE_H_
