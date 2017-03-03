#ifndef SEQUENCE_TERM_SUM_CONTROLLER_H
#define SEQUENCE_TERM_SUM_CONTROLLER_H

#include <escher.h>
#include "graph_view.h"
#include "curve_view_range.h"
#include "vertical_cursor_view.h"
#include "../../shared/curve_view_cursor.h"

namespace Sequence {

class TermSumController : public ViewController {
public:
  TermSumController(Responder * parentResponder, GraphView * graphView, CurveViewRange * graphRange, Shared::CurveViewCursor * cursor);
  const char * title() const override;
  View * view() override;
  void viewWillAppear() override;
  bool handleEvent(Ion::Events::Event event) override;
  bool moveCursorHorizontallyToPosition(int position);
  void setSequence(Sequence * sequence);
private:
  constexpr static float k_cursorTopMarginRatio = 0.07f;   // (cursorHeight/2)/graphViewHeight
  constexpr static float k_cursorRightMarginRatio = 0.04f; // (cursorWidth/2)/graphViewWidth
  constexpr static float k_cursorBottomMarginRatio = 0.15f; // (cursorHeight/2+bannerHeigh)/graphViewHeight
  constexpr static float k_cursorLeftMarginRatio = 0.04f;  // (cursorWidth/2)/graphViewWidth
  class ContentView : public View {
  public:
    ContentView(GraphView * graphView);
    void layoutSubviews() override;
    GraphView * graphView();
  private:
    class LegendView : public View {
    public:
      LegendView();
      void drawRect(KDContext * ctx, KDRect rect) const override;
    private:
      void layoutSubviews() override;
      int numberOfSubviews() const override;
      View * subviewAtIndex(int index) override;
      ExpressionView m_sum;
      PointerTextView m_legend;
    };
    int numberOfSubviews() const override;
    View * subviewAtIndex(int index) override;
    GraphView * m_graphView;
    LegendView m_legendView;
    constexpr static KDCoordinate k_legendHeight = 28;
  };
  ContentView m_contentView;
  CurveViewRange * m_graphRange;
  Sequence * m_sequence;
  Shared::CurveViewCursor * m_cursor;
  VerticalCursorView m_cursorView;
  int step;
};

}

#endif