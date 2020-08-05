#ifndef ICONS_H 
#define ICONS_H 1

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#     include <wx/wx.h>
#endif

#include <wx/filename.h>
#include <wx/mstream.h>

extern void initialize_images(void);

extern wxBitmap *_img_findit_pi;
extern wxBitmap *_img_findit;

#ifdef PLUGIN_USE_SVG
extern wxString _svg_findit;
extern wxString _svg_findit_rollover;
extern wxString _findit_toggled;
#endif

#endif /* ICONS_H */
